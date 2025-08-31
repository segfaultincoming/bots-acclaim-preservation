# Let the grown-ups handle it!

I have upped my skills, but I also need to make things faster. I need to see actual game code and learn about a million things while I look at it.

## Communities reachout

Obviously, I need help with unpacking. Let the grown-ups handle it!

I've reached out to several communities:

1. [RaGEZONE](https://forum.ragezone.com/)

- There are multiple threads on BOTS server development, plus a guy who claims that he unpacked the client! He was online 3 days again!

2. [Nathan Baggs](https://www.youtube.com/@nathanbaggs)' Discord server.

- I watch Nathan's videos for quite some time now, maybe he was the reason why I thought that I have to reverse engineer this game. Long story short, he does what I _try_ to do.

## GameGuard

Well, community reachout worked!

Crucial information from Nathan Baggs' Discord:

- [mradamdavies](https://github.com/mradamdavies) from Nathan Baggs' Discord sent me crucial information about BOTS' GameGuard. He remembered a thread from a while ago, which contained explanation of [how to defeat and emulate](https://www.unknowncheats.me/forum/anti-cheat-bypass/61084-e-book-defeating-and-emulating-incas-nprotect-gameguard.html) nProtect's GameGuard.
- @foreverbronze sent me a GitHub repo explaining [how to bypass the GameGuard with hooks](https://github.com/neetjn/oro-bypass). For a different game, but more or less the same GameGuard.

### Server communication

> The server sends out four DWORDs to the game client at
> random intervals (index, value1, value2, value3). The game
> client takes these values and sends them to GameMon.des (the
> process of GameGuard) through a pipe.

In desperation, I think that there's no way to unpack the client... does the client require these values before it jumps to the OEP?

How do I go from here?

## Time to learn

It was clear that even though I had all of this information about the GameGuard, I had to do a lot of work to get to the point, where I can reverse engineer or even just unpack this thing.

### Tooling is crucial

So far, when I was interested in something, the AI was writing the tools for me. Don't. Do. That. The reverse engineering community is HUGE! If you need a tool there is a 99.99% chance that it exists.

### Materials

[The Cyber Yeti](https://www.youtube.com/@jstrosch)'s videos are a gold mine! I've gone through his x86 assembly lectures and saw his unpacking process (not Yoda, but still unpacking)! Thank you!

[Nathan Baggs](https://www.youtube.com/@nathanbaggs) was already mentioned, but it's worth mentioning him again. He has 100% stumbled upon packed game, I will just watch his videos before I go to sleep and hope that I will see one. Entertaining, useful, thank you!

## 2:00 AM

I guess that I was so focused on learning and I couldn't fall asleep. And out of nowhere...

### Realization

GameGuard contained code in its `*.des` files. The GameGuard was also a system service. I didn't install the game, I didn't have the service! Remember, I used zipped version of the client! No GameGuard service running, no party!

### Ancient history

How do you find an installer from 2006?! This won't be as easy as visiting the [Internet Archive](https://archive.org/).

Well... not as easy, but not as hard as I thought.

I visited BOTS' website from 2007, I went to the download page and... 404! I got a 404 on the installer, but 200 on the installer's name - `BOTS_11-12-2007.exe`!

Hippity, hoppity, some Australian archive website has it! [AusGamer](https://www.ausgamers.com/files/download/33532/bots-client-v20071211), I believe that before my [clients repo](https://github.com/segfaultincoming/bots-acclaim-clients) that was the only publicly available installer of the original client. Thank you for preserving game history (not only BOTS, but thousand of other games)!

A few minutes and heart attacks later, I have it. I've copied it to external storage in case Windows detects it as a threat.

## I have to go to sleep

We have a visit from C-level management tomorrow. It's 2:30AM. I have to wake up at 6:00AM. Wish me luck!

## Plan for tomorrow:

1. Install the game from the installer
2. Use x64dbg to debug it
3. Try to get to the unpacked code
