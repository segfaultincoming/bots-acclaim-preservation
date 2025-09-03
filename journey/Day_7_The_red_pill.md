# The red pill

I knew what I have to do today - fix the [Import Address Table](https://en.wikipedia.org/wiki/Portable_Executable#Import_table).

But you know what? I want to have some fun. I believe this is the first time I've spent so much time in x64dbg or Ghidra. These tools are so OP! I learn things with every button press!

## Coffee, set, go!

See, I can't do a lot of static analysis with missing imports... and Scylla doesn't seem to resolve the dynamically assigned pointers automatically...

~150 missing imports.
12 clicks per import.
1800 clicks in total.

I got it. I've even saved the tree for the next time. Now I have an executable with fixed (maybe) imports!

## x64dbg

I've identified `0x00435DD0` as the entry point, but it does look kind of fishy now.

Looking closer into it, it mainly contains code for displaying [MessageBoxA](https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-messagebox) to the user. If I were making a game (or anything really) this would've been wrapped into some function, i.e. `ConnectToGameGuard()`.

So my main function (oversimplified) would've looked like that:

```pseudo
main {
    SetupGameEngine();
    ConnectToGameGuard();
    ConnectToGameServer();
    PlayGame();
}
```

And from the last few days we already know that the game has a login screen. Where is it?

Anyways, let's continue with our x64dbg exploration and come back to the login screen later. I have an idea how to find it in Ghidra.

If you right click on the address, you can find references to it.

> [Right click on 0x00435DD0 -> Find references to -> Selected address] or [Alt + R]

What do we see here! Virtual Address Table (or as Google suggests, [Page Table](https://en.wikipedia.org/wiki/Page_table)).

```asm
00401000 | CC                       | int3
00401001 | CC                       | int3
00401002 | CC                       | int3
00401003 | CC                       | int3
00401004 | CC                       | int3
00401005 | E9 66560E00              | jmp bots.dat.4E6670
0040100A | E9 51270E00              | jmp bots.dat.4E3760
0040100F | E9 8CC11F00              | jmp bots.dat.5FD1A0
....
00404B79 | E9 F27D1300              | jmp bots.dat.53C970
00404B7E | E9 DD290400              | jmp bots.dat.447560
00404B83 | E9 587D0200              | jmp bots.dat.42C8E0
```

The [int3](<https://en.wikipedia.org/wiki/INT_(x86_instruction)#INT3>)-s at the beginning look pretty suspicious. I wouldn't be surprised if there's logic to send debuggers there. Thankfully, we use [ScyllaHide](https://github.com/x64dbg/ScyllaHide), so we're well hidden.

If I'm not wrong those are `15,230` entries in this virtual table. I don't want to be admitted to mental asylum, so I won't go through that. But it's good to acknowledge it.

The game is not calling its functions directly, it's using the address table starting from `0x00401000`. This can confuse static analysis tools.

## Ghidra

The login screen. There must be a function that displays it. Luckily, I have the client and most of its UI components are [.tga](https://en.wikipedia.org/wiki/Truevision_TGA). I can open them in more or less any "photo viewer". The UI elements are conveniently stored in `data/ui`.

### UI elements

Back in the day there were mods to change the login screen appearance, so naturally I was "modding" it as well. I think it was only one file? If so, it must be pretty large... let's sort by size.

Aaaand it was the first file - `ui_100.tga`. But I was interested to see what the other big files are:

- `ui_100.tga`, login screen
- `ui_130.tga`, that's the loading screen BEFORE the login screen. This can be huge.
- `ui_200.tga`, lobby screen
- `ui_300.tga`, room screen
- `ui_400.tga`, shop screen
- `ui_700.tga`, bot info screen

I think that I see pattern here? Could the leading number represent a different game section?

- `ui_131.tga`, channels screen (part of login and server selection)
- `ui_120.tga`, create bot screen (part of login and server selection, again)

One more for sanity check...

- `ui_211.tga`, Lobby, Friends and Guild tabs (part of the lobby screen)
- `ui_303.tga`, Ready button (part of room screen)

So I'm confident now:

- `1XX`, loading screen
- `2XX`, lobby screen
- `3XX`, room screen
- `4XX`, shop screen
- `5XX`, some lonely "bonus" icon
- `6XX`, missing
- `7XX`, bot info screen
- `8XX`, I think that's the social system - trading, gifting and mail
- `9XX`, system elements - cursor and generic message box

### Login screen

Given that I know the resource of the login screen, I can just search for it in Ghidra's strings.

Aaaand it's `0x00510170`. This even plays the background music. So, how do I go from here?

My logic is simple. The entry point should never be called from inside another function. I haven't seen code that does:

```pseudo
main {
    // Do start up stuff...
    otherFunction();
}

otherFunction {
    // Imma just call main again, aight?
    main();
}
```

I may be awfully wrong, but let's see...

## Back to x64dbg

So the plan:

1. Open the executable in x64dbg
2. Go to the login screen address (`0x00510170`)
3. Find references to, until I stumble upon a function that doesn't have references to it

Remember, there's a virtual address table, hence I'm interested in the jmp address, rather than the virtual table address references to.

Login screen should be called only once, so it shouldn't be that hard.

I've found that `0x0044D500` invokes another function that invokes the login screen and most importantly - `0x0044D500` doesn't have references to it! I think that's the real entry point now.

## Back to Ghidra

I want to explore the virtual address table, see how it looks like.

```asm
0040173f e9              ??         E9h
00401740 fc              ??         FCh
00401741 fd              ??         FDh
00401742 1f              ??         1Fh
00401743 00              ??         00h
```

A lot, and I mean A LOT, of the instructions are not disassembled. Let me try to manually disassemble few with the `D` key. New functions were disassembled.

Man, I want to write a script that does that for me. I obviously want to see how deep the rabbit hole goes.

## Deviation

Obviously my plan is not just to reconstruct the import table anymore:

1. I want to verify the real OEP
2. I want to explore Ghidra scripts

Those tools are so kewl!
