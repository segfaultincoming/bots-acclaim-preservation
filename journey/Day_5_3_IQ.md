# 3 IQ

After yesterday's realization and the finding of the original client, I was so hyped! I just wanted to get started!

## Office time

Do you remember the days when we had to go to the office every day? Bring. Them. Back.

I've had 30-minute discussion with [zvchei](https://github.com/zvchei) about my project. He used to do malware analysis back in the day. It was more or less general discussion - what tools he used, what he did, what should I do next?

- My tooling now was more or less correct. I've had everything necessary.
- I had memory dumps from sort of running process, but I had to find the OEP. Manually? Going through hundreds of functions is not pleasant, but not that hard.

### Learn while you work

I've just played videos from [The Cyber Yeti](https://www.youtube.com/@jstrosch), while I was doing my day-to-day tasks:

1. Packers try to confuse static analysis tools. You have to spot those regions and manually disassemble the code.
2. Modern era analysis - [Time Travel Debugging](https://learn.microsoft.com/en-us/windows-hardware/drivers/debuggercmds/time-travel-debugging-overview)
3. Basic x86 assembly knowledge

- [Prologue and epilogue](https://en.wikipedia.org/wiki/Function_prologue_and_epilogue)
- Basic work with registers
- Reading/writing data

### Scavenger hunt

If you work in the IT sector, there's a good chance that there's an old laptop somewhere in the office storage.

Few weeks ago, we were searching for laptop with specific [network interface controller](https://en.wikipedia.org/wiki/Network_interface_controller) to reproduce and fix a [WebRTC](https://webrtc.org/) bug.

I remembered that we found a laptop with triple the thickness of my current one and double my weight. This surely is Windows 7 era laptop.

2 minutes later: I open it and I see this shiny Windows 7 sticker below its keyboard. I must have that.

Can I have it, pwetty pweasy?

- Yes. Take it.

Some people laughed, but little did they know that I now own the ultimate weapon for defeating any 2006 game security. _*Laugh in 2006 hardware*_

### Real hardware vs Virtualization

See, I've used Mac for quite some time in mid 2010-s. In fact, I only owned Mac devices. This was good for my day-to-day work, but I wanted to play some games. So my obvious choice back then was virtualization. This didn't produce good results - some games weren't starting, others were missing UI elements, others were showing blank screens.

I don't think that BOTS was handling virtualization that well, so maybe... if I start it on real hardware I will at least see the login screen of the game.

## Current knowledge

1. The `patch.ini` file contained game server information. Which IPs we connect to.

- Playing around with the other clients (Ohka BOTS and BoutCheetah, sorry guys) I found out that I can just put 127.0.0.1 and spin up simple echo server on port `11000`

2. I needed to see the login screen have any chance of unpacking the executable

## Honey, I'm home...

... and I will work on my reverse engineering project and I will watch the football game afterwards. Every wife wants to hear those words. Trust me.

### Windows 7 installation

We're kind of spoiled with today's Windows installation:

1. Download the official ISO from Microsoft
2. [Create the thumb drive](https://support.microsoft.com/en-us/windows/create-installation-media-for-windows-99a58364-8c02-206f-aa6f-40c3b507420d)
3. Stick it in the USB port
4. Find the boot selection key (the hardest part)
5. Install

Needless to say, it wasn't that easy for Windows 7. I've had to make some changes in the boot menu settings, find some drivers, find the correct USB port (yes, not all USB ports supported booting from them). After an hour or so I finally had Windows 7 running.

Afterwards I've had to install dozen of updates (mentioned in Day 1), .NET runtimes, C++ Redistributable packages and find a way to use my wireless mouse on it.

## It's alive!

I have edited the `patch.ini` with `127.0.0.1`...
I have my echo server running...
I have started the executable...

LOGIN SCREEN!

THE 2007 LOGIN SCREEN WELCOMES ME!

HUGE!

It's working! The past 5 days I've spent on executable that wasn't working. You can tell that I don't have a lot of reverse engineering experience, right?

## Matchday

I have to watch my team's Europa Conference League Play-off, but the plan for tomorrow is clear:

1. Debug the working executable with x64dbg
2. Unpack it
