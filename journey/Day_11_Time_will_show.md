# Time will show

Crashes it is.

It's been a few days of radio silence, but I've been working on the project actively. I've started to debug the executable and patch the missing imports or missing structs.

## Process

My process is quite simple, maybe inefficient, but it works. It's a combination of dynamic and static analysis:

1. Load the executable in x64dbg
2. See where it crashes
3. Do static analysis in Ghidra

At first, it was quite hard to distinguish between missing imports or missing structs initialization, but I got pretty good at it.

If I see `jmp`/`call` to an address it's missing import.

If I see dereferencing of address, it's struct.

```asm
call [0x00bb0ef4]       ; Import
; ...
CMP [0x00b0aa24], 0x0   ; Struct
; ...
MOV ECX, [0x00b0aa24]   ; Struct
```

It may be naive, but so far it works pretty well.

### Initialization

As mentioned before, some of the addresses are pointers to initialized structs. And as I've found out, some of the functions called are pretty convenient for me - they check if the object is initialized (dereferenced address is not `0x0`) and if not, they initialize it. Most likely a singleton pattern.

Following that logic, I've identified and reset 8 addresses.

## GameGuard

I knew that this would be a pain in the ass at some point... here it comes.

During debugging I've found function at address `0x006ebd00`, which does exactly what I expect from an anti-cheat system, start a separate process:

```asm
006ed884 | PUSH | EBX
006ed885 | PUSH | EDX
006ed886 | PUSH | 0x00bab8a0
006ed88b | CALL | dword ptr [->KERNEL32.DLL::CreateProcessA]
```

Not to mention the countless references to GameGuard strings.

### Yet another address table

Starting at address `0x00a55000` there's yet another virtual address table. During constructor initialization, this table is iterated and it's members are called.

At address `0x00a5519c` you can find the address of the GameGuard's initialization function (`0x006ebd00`).

### What if...

As you can imagine, the GameGuard's initialization function is complex AF, especially when you're trying to debug it. The function's approximation is `1328` lines long - you can imagine how long it is in raw assembly. But what if... we just skip it?

### PS

I did try to debug it and make sense of it, but it's pretty hard. During that process I've discovered that it's trying to dereference `0x00bab9e4`, so I've zeroed it out. I now think that this may have been a mistake, but you will find out why a little bit later.

## GameGuard Skip?

After setting the address at `0x00a5519c` to `0x00000000`, things started happening. For the first time I was able to get into the function I've identified as `WinMain` (`0x00435dd0`)!

Not only that, but that's what is generated in `boutlog.txt`:

```
----------- 2025/09/20 20:31:11 -----------
BSScript::OpenScript() - C:\Program Files (x86)\BOTS/script/string.bin¿­±â
BSScript::OpenScript() - codetype 1 size 25504 mem 63045736
FindWindow( "Bout", NULL )
GetServerIP( buf )
GameProcInit()
BSScript::OpenScript() - script/slangs.bin¿­±â
BSScript::OpenScript() - codetype 1 size 6865 mem 63045736
ArgumentsProc(pCmdLine)
RegisterMotionString()
RegisterBattleMap()
BSScript::OpenScript() - C:\Program Files (x86)\BOTS/script/map_battle.bin¿­±â
BSScript::OpenScript() - codetype 1 size 998 mem 54613472
RegisterPlanetMap()
BSScript::OpenScript() - C:\Program Files (x86)\BOTS/script/map_planet.bin¿­±â
BSScript::OpenScript() - codetype 1 size 4544 mem 63177496
RegisterBaseMap()
BSScript::OpenScript() - C:\Program Files (x86)\BOTS/script/map_base.bin¿­±â
BSScript::OpenScript() - codetype 1 size 1520 mem 54613472
WinInit( hInst, nCmdShow, &g_hWnd, &hAccel )
```

The log messages are added, before the function itself is called, so... yes, `WinInit` is failing. Kind of!

### Hello, CreateWindowExA!

Yes, for the first time I see a created screen, when starting the game from the debugger!

A screen, but blank. Blank, but a screen!

We've got a failure at an interesting location, function at address `0x00452490` on instruction:

```asm
004524B0 | cmp dword ptr ds:[eax+10], 0
```

This told me one thing... it has been called with invalid parameter, so...

#### Who called us?

I'm ashamed, but it took me too much time to make sense of it. At some point during execution, we register some kind of event handler (still not sure where, how and what) and it's calling `0x00437CC0` as a handler.

It's doing a lot of things, but few instructions got my attention:

```asm
00438030 | cmp dword ptr ds:[B0AA24],0
00438037 | je 0x00438065
00438039 | mov ecx,dword ptr ds:[B0AA24]
0043803F | call 0x00402428                  ; VAT at beginning, JMP 0x00402428
00438044 | mov ecx,dword ptr ds:[B0AA24]
0043804A | call 0x00401E1A                  ; VAT at beginning, JMP 0x004526a0
0043804F | mov ecx,dword ptr ds:[B0AA24]
00438055 | call 0x004031F7                  ; VAT at beginning, JMP 0x00452520
0043805A | mov ecx,dword ptr ds:[B0AA24]
00438060 | call 0x00404345                  ; VAT at beginning, JMP 0x004525B0
; ...
0043809D | mov dword ptr ds:[A55FD4], 0
; ...
004380BF | mov dword ptr ds:[A6D9A4], edx
```

So, what the dereferenced addresses contain?

```
0x00b0aa24 = 0x025bccb0
```

This is obviously an address to _something_. This is the value that I saw in the registers when entering `0x00452490`.

So, following my procedure, this doesn't look like a missing import.
And seeing addition/subtraction from it... yep... _yet another address table_.

#### How do I patch it?

I don't know what it's supposed to point to, only if I had a way to see that... and I do! The old PC? It will come in handy again!

```
0x00b0aa24 -> dynamically allocated address -> 0x009a5244 -> 0x004041CE
```

The dynamically allocated address seems to be allocated on the heap. I've spent quite some time to see where the initialization is happening, but I couldn't figure that out.

#### Let's do something dumb

I will patch the address with the next one in the chain... so `0x00b0aa24` -> `0x009a5244`. Will that work?

It seems that it cured the symptom. But will it be a permanent fix? Time will show.

## Will I regret it?

As mentioned, I've just zeroed out `0x00bab9e4`. But taking the recent fix of `0x00b0aa24` into consideration, I'm no longer sure that this was the correct decision.

I've taken a peek at what's on `0x00bab9e4` in a running process... and it's yet another pointer and it points to the heap. It's the middle (give or take) of an initialized object.

## Next

I think that I will ignore the `0x00bab9e4` problem for now. I will focus on getting `WinInit` successfully executed. If during that process I find that it's mandatory to initialize that... I will look for a way to do it.
