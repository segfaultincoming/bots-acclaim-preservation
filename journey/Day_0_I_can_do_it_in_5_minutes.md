# "I can do it in 5 minutes"

Finding an old game on an old HDD... a game that you've spent hundreds of hours on. A game that you still remember where every Saturday and Sunday had a double experience event from 16:00 to 18:00 (EET Time), and a group of 8 people - friends - grinded non-stop just to take full advantage and potentially gain a level or two.

I hope that everyone experiences that level of nostalgia.

## How do I run it?!

### Private servers

Yes, there are private servers of the game. As of today, 2 in fact:

1. [OhkaBOTS](https://ohkabots.ohkaspace.com/)
2. [BoutCheetah](https://zylongaming.com/)

Guys, please continue with your great work! And thank you for letting me play the game again after 17 years!

### But really... how do I really run it?

Given that I've hosted a server for another game (MuOnline), I kind of know how it works - the client sends packets, the server responds to them, bada bing bada boom - game.

Oversimplified, but yes, when you have the graphics part (client), it's pretty easy.

There are some server files released back in the days:

1. [BotsEmu](https://github.com/Will-Scarlet/BotsEmu)
2. [RageZone post](https://forum.ragezone.com/threads/bots-online-server-files-client.843057/) - which I've found on my HDD as well!

BotsEmu has some documentation for the packets, so it might be really useful!

So, the plan is clear:

1. Look at the client's socket reads/writes
2. Create a server that responds to those packets

## Let's battle!

The first thing that comes to mind - open the executable (aka bots.dat) in [Ghidra](https://github.com/NationalSecurityAgency/ghidra), follow the code and get to the packets part.

### Import, Analyze...

...aaaand what the \*\*\*\* is this?! This entry point makes no sense, but let's follow the logic. I will get there.

### Oh, I 'member!

Packed executables, yeah... If you're a game studio (even in 2007), you want to use those. Let's see which packer they used.

### In myself, I trust

How do you find which packer they used? Google (or some LLM) recommended me [Detect It Easy](https://github.com/horsicq/Detect-It-Easy).

> Crypter: Yoda's Crypter(1.x)

## 2004 packer vs Software Engineer

What a joke! I have 11 years of experience as a software engineer! It's a 5-minute job!

I've searched for more information about Yoda's Crypter. Eventually I found out that there are unpackers. Did I say 5-minute job? I meant 1-minute job!

The plan is clear, let's call it a day.
