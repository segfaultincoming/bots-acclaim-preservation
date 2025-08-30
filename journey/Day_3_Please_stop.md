# Please, stop!

The last time, I found out that `QuickUnpack` produced an unpacked executable, which contained the C++ Runtime. Today is the day that I will use the correct settings for it, find the correct Entry Point (EP) and start analyzing the code.

## QuickUnpack

`QuickUnpack` provides a lot of options. Different OEP (Original Entry Point) finders, hooking to library functions and ways to reconstruct the whole executable.

As you can tell, this is my first time using it, so it will take some trial and error and I will eventually get it.

## Splash screen

The behavior of the client, which I found on my HDD is a bit strange, but the game and GameGuard servers are down for god knows how many years. When I start the executable, I see the GameGuard's splash/logo screen and the program terminates. Obviously it can't connect to the GameGuard's servers and it's terminating the process. Makes sense.

The GameGuard is loaded by the main executable, so it shouldn't be a problem. The load sequence should happen after unpacking is finished. Or at least, when part of it is unpacked, then I can analyze the next unpacking stub. This is generally [how the packing works](https://medium.com/@dbragetti/unpacking-malware-685de7093e5).

## Settings & OEP finders

I can't get in details what settings I've tried and which OEP finders. But I had 2 different OEP-s found and 2 different executable files produced. Let's see which is the correct one and I will come back to the exact settings.

## AI code analysis

This time I've decided to directly export the C code approximation, in that way the AI will have the whole file and it could automatically search and create scripts that will help us with the analysis.

~1.4 million lines of C code. Testing AI's limits wasn't included in today's plan, but here we go!

### Find the entry function!

That should be easy, Ghidra literally names the function at EP as `entry`.

Well, there are a few other interesting functions - [\_DllMainCRTStartup](https://learn.microsoft.com/en-us/cpp/build/run-time-library-behavior?view=msvc-170) and [DllMain](https://learn.microsoft.com/en-us/windows/win32/dlls/dllmain). Claude identified those! It's still promising, we have `entry` (from EP) and 2 other functions. 33% chance that we got the right one, else we just try the other 2.

### Claude, analyze!

Simple as that, let Claude write helper scripts and analyze the unpacked binary. Later on we would be able to share these scripts, so that everyone can unpack and analyze the BOTS code. That's what we want!

### We found the needle!

Ah, a reference to `nlogcmd.dll` (GameGuard)! Hello, unpacked executable! Let's see how it's called, so that I can look at the right function(s) in Ghidra.

### High (not related to Snoop Dogg) entropy!

After Claude wrote a few scripts to analyze the GameGuard's invocation, it found sections with high entropy. Let Claude crack them open!

Another layer of obfuscation/packing (again). Normal and promising!

### Claude, work!

Thankfully, the `nlogcmd.dll` is not packed, so we can easily see its functions, `NLOGCMD_Startup` seems like a good candidate to search for. But let's give it some slack - search for references to functions starting with `NLOGCMD_*`!

Analyze the C code approximation, find where `NLOGCMD_*` are invoked, create scripts for each step, reconstruct the executable.

Go!

### Enough!

Please, stop! 20 scripts in a few minutes?! `gameguard_string_finder.py`, `comprehensive_gameguard_string_finder.py`, `final_final_work.py`. Can't you just edit the same scripts?

And it's the C++ Runtime again. Another few hours wasted.

## AI slop

I'm left with 20 scripts, which essentially do nothing. One of them contained (I'm serious) bunch of prints with emojis and statements like "We've found the GameGuard's start up logic", "We've successfully created deobfuscator for the second stage of packing". It constantly derailed to different topics, it couldn't stay focused on the given task.

I guess that's because it didn't know the exact next step. But it was at least confident that he's on the right path. He had to travel from Germany to England, but he also visited Japan, South Africa and Uruguay along the way. Efficiency!

Bottom line is, I think that AI is at least one year further away from taking my job now. It is currently (2025) quite helpful, when you give him specific tasks, but when you ask it to do research on its own... currently, I see no chance of it unpacking this executable or even helping me with it.

## Different perspectives

While waiting for Claude to do its work, I was already researching different approaches.

1. [Emulation](https://www.youtube.com/watch?v=b5-oTMcBJQ0)

- [Unicorn Engine](https://www.unicorn-engine.org/)
- [Qiling](https://github.com/qilingframework/qiling)

2. [Manual Unpacking of Yoda](https://www.youtube.com/watch?v=VxMqMXpMMM4)

#### Emulation

I don't like saying it, but I've made the same mistake. I asked the AI to write emulation scripts for the emulation. It did its job, but once again... too many patches, too much slop, too many emojis! Seriously, is puttin emoji in every sentence the standard now?!

❌ Even though the Qiling framework executed over 1 million instructions, it didn't produce anything useful. I've tried dumping the executable at a few points - nothing useful.

#### Manual Unpacking 📦

[Cabal Online](https://cabal.playthisgame.com/en) used the same packing 13 years ago or so, the process should be more or less the same. 🤩

(3 emojis are enough, I won't use them anymore. I promise.)

[KiUserExceptionDispatcher](https://momo5502.com/posts/2024-09-07-a-journey-through-kiuserexceptiondispatcher/) is invoked after a few returns...

The best I can do is to identify which instruction causes this and try patching instructions before that...

Essentially, I tried taking different jumps. There are a lot of [jmp](https://www.felixcloutier.com/x86/jmp) instructions. A lot. I've tried using jumps before the exception is thrown... no result.

## Now what?

To be fair, I don't know what to do at this point. I need some help. I need to learn more about reverse engineering processes and come up with a concrete plan and evidence of what is happening.

The plan for tomorrow is clear:

1. I will have to reach out to some reverse engineering communities to make things quicker.
2. I will also have to up my reverse engineering/analysis game to see this project through!
