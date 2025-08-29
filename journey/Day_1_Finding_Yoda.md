# Finding Yoda

The plan for today is clear: find a working download for an unpacker, unpack it, and explore it.

## I prefer younger...

... packers. Seriously, it took me around 2 hours to find an unpacker. I found [this thread](https://forum.tuts4you.com/topic/22277-unpacking-yoda-10-13-exe/) and it seemed that `RL!deYC` or `CPS!UnYoda` would do the work. However, I couldn't find a link that works.

After some more digging, I found `QuickUnpack`. Took me around 30 minutes to find a link to this one! Found [reToolkit](https://github.com/mentebinaria/retoolkit) along the way! I'm sure that this will be useful!

It would've been easier if it was packed by something from 2 years ago.

## Please click the Ready button

Alright, open QuickUnpack, load the exe, and let's get ready to work!

Aaaand I can't run the x86 version on my modern PC...

### VirtualBox it is

Windows XP, my old friend. And I thought it couldn't get more nostalgic!

Aaand it couldn't properly install in VirtualBox. Couldn't be bothered, I installed Windows 7.

Aaand you can't open web pages, you can't install Chrome/Firefox/Opera. Online installers? Nah, there's a [missing root certificate update](https://support.microsoft.com/en-us/topic/support-for-urgent-trusted-root-updates-for-windows-root-certificate-program-in-windows-a4ac4d6c-7c62-3b6e-dfd2-377982bf3ea5).

Today's kids are spoiled with their 64 bits. This makes me wonder how many things would be lost because of backward compatibility? If you're reading this in 2035 and I've succeeded in releasing the first public (and working) server files for BOTS - can you run them?

Anyways, I've found what I need [Supermium](https://www.win32subsystem.live/supermium/) and the needed OS updates.

## Time to unpack!

Load the executable in `QuickUnpack`, detect the Original Entry Point (OEP), click "Full Unpack", and done!

## Let's load it in Ghidra!

Alright, a lot more functions! Meaningful strings! Boys, we did it!
