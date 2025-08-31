# Did I?

Well, my team lost. We're out of the Europa Conference League, but today is the day I win!

## Login screen

So, as mentioned before, we have the login screen, but interestingly after 10-20 seconds I get a message saying: `Fail to connect the GameGuard update server. Please try again after a while, or check personal Firewall settings if any.`.

This is huge. We're running the unpacked executable, before we try to connect to the GameGuard's server.

## Debugging

Alright, let's step through the executable with x64dbg.

It clearly runs interesting intructions.

```asm
mov byte ptr ds:[eax], 0        ; Write a null terminator (0x00) at the memory location pointed to by EAX.
                                ; This effectively erases (overwrites) the first character of a string.

inc eax                         ; Increment EAX to point to the next byte.

cmp byte ptr ds:[eax], 0        ; Compare the next character in the string with 0x00.
                                ; If it's not zero, it means the string still has characters left.

jne bots.BF4747                 ; Loops back to repeat the process and overwrite the next character.
```

I saw those instructions executed for `nlogcmd.dll`, `boutcmd.dll` and Windows API functions. It's clear:

1. We're after the unpacking stub.
2. The Import Table is effectively wiped.
3. From this point on the executable will use addresses to functions, saved in memory.

## Another exception

Even though I saw the instructions above, the executable was still not starting, when ran through x64dbg. Most probably timing-related anti-debugging technique.

Here we go again...

## Wait a minute!

Can't I just attach to the running process? Can I?

YES, I CAN!

1. Run the `bots.dat` executable
2. Quickly go to x64dbg
3. Attach to the process
4. Pause the execution

Go to the current function's prologue:

```asm
push ebp
mov ebp,esp
```

Let's see what we have...

## OEP?

The function starts at address `0x00435DD0` and it contains a lot of interesting instructions:

```asm
00435EC7 | push bots.dat.9A3FF4     ; 9A3FF4:"GetServerIP( buf )"
00435F05 | push bots.dat.9A3FE0     ; 9A3FE0:"GameProcInit()"
00435FBE | push bots.dat.9A3F90     ; 9A3F90:"RegisterBattleMap()"
00435FE7 | push bots.dat.9A3F78     ; 9A3F78:"RegisterPlanetMap()"
00436010 | push bots.dat.9A3F60     ; 9A3F60:"RegisterBaseMap()"
00436039 | push bots.dat.9A3F28     ; 9A3F28:"WinInit( hInst, nCmdShow, &g_hWnd, &hAccel )"
```

This is pushing strings (function names) onto the stack. Let's deep dive:

```asm
00435EC7 | 68 F43F9A00              | push bots.dat.9A3FF4                             | 9A3FF4:"GetServerIP( buf )"
00435ECC | 68 0873A600              | push bots.dat.A67308                             |
00435ED1 | E8 0CE3FCFF              | call bots.dat.4041E2                             |
```

So `0x4041E2` is called with 2 arguments - _something_ and the function's name.

Oh, I remember! The client has log file located in `log/boutlog.txt`, if we open this file...

```
FindWindow( "Bout", NULL )
GetServerIP( buf )
GameProcInit()
...
ArgumentsProc(pCmdLine)
RegisterMotionString()
RegisterBattleMap()
...
RegisterPlanetMap()
...
RegisterBaseMap()
...
WinInit( hInst, nCmdShow, &g_hWnd, &hAccel )
```

BOYS! I think we have it! This is definitely the loading sequence of the BOTS client!

## Let's run it

Let's try to run it!

[0xc0000005](https://learn.microsoft.com/en-us/shows/inside/c0000005) access violation exception.

Well, this is normal:

1. The import table is erased
2. The executable unpacks, probably in a region without execution rights

## I WANT A WIN!

I've made huge progress today and I want to go to sleep with a win. Small win, but a win!

The plan for tomorrow is clear:

1. How do we fix the import table?

- Everyone and everything is suggesting [Scylla](https://www.eyehatemalwares.com/reverse-engineering/scylla-x6486/) or [ImpREC](https://github.com/trietptm/Import_REConstructor-Archive).

2. [Detect It Easy](https://github.com/horsicq/Detect-It-Easy) still shows some obfuscated sections

- Maybe this is normal? Are these sections, where the different addresses are kept?
