# Ah shit, here we go again.

Those functions still don't make a lot of sense, but there are a lot of them, and God knows what engines and externals they've used.

## Let's try to make sense of it

I've started bombarding [Claude](https://claude.ai/) with disassembly from the unpacked version. It started spitting out so many scripts to help me with the analysis of the executable and explain each function to me.

We're close! Even though some sections show high entropy, there's a lot of meaningful code!

## Let's go from the beginning

I've started collaborating with Claude: I give him the entry function, he asks me to see functions that are called inside and they're interesting to him.

Nothing really interesting happened during that collaboration. Just a lot of back and forth. We've identified memory arrangements, an additional layer of masking (XOR-ing some chunks here and there)...

Until...

## C++ Runtime

During this whole time, we were analyzing the C++ Runtime. Yeah. Nice.

I felt betrayed... after a few hours of poking around the code, trying to implement unmasking of the chunks and... Claude told me: "Hey, this is actually the C++ Runtime".

## Unpacking. Again!

Let's start over with the amount of knowledge I've gathered so far, it should be a piece of cake. I won't be tricked like this again!

It's 1:00 in the morning. I was planning to go to the office tomorrow. Nah, I'll work from home.

The plan for tomorrow (today):

1. Unpack the executable (again)
2. Analyze the code
