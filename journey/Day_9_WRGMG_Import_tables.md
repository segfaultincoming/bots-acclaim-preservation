# What really grinds my gears: Import tables

I decided to look into fixing the import tables.

## Me no likey

Is it really 2025, and are we still using [that import table](https://www.youtube.com/watch?v=0O-Rhes0dFI) structure?

### Scylla

When I was manually resolving imports in Scylla on [day 7](Day_7_The_red_pill.md), I saw that some of the thunks contain entries for more than one DLL:

```asm
0x0000001 kernel32.dll -> LockFile
0x0000002 ntdll.dll -> RtlAllocateHeap
```

Back then, I didn't know much about import tables, so I didn't pay much attention to it; I was imagining it being close to modern-day imports:

```pseudo
import LockFile from kernel32.dll;
import RtlAllocateHeap from ntdll.dll;
```

Boy, was I wrong! And this caused the `RtlAllocateHeap` to be imported from `kernel32.dll`...

Really, `Scylla`? Didn't you feel like relocating the `RtlAllocateHeap` import to `ntdll.dll`?

Did I really need to find the `Ctrl+G` (Get Imports) shortcut today by accident to make that happen? And how tf is this logical?

Also, when hitting `Get Imports`, some of the manually resolved imports disappear. Great. Fix 20 imports, get to `ntdll.dll` in a `kernel32.dll` thunk, fix it, start over.

## Tooling

I feel that the import reconstruction tooling is stuck in 2007. In my mind it's super easy to remove or replace different imports. Let's say that I just want to move `RtlAllocateHeap` to some `ntdll.dll` thunk. Well, none of the tools offer that.

I can't even remove a single entry from a thunk.

### Scylla

Yes, I've saved the manually fixed import tree from day 7. However, I can't use it unless I attach to a running process.

But if you can fix another dump from a running process, that means the import reconstruction is more or less static, which means you should be able to just import the Scylla-generated XML file and use it.

Well, nope.

## I need rest

Seriously, I knew that the import reconstruction process would have a lot of manual steps, but this much?

I've spent the whole day digging up information on import tables and trying out different tools to get exactly 0% progress.

The plan for tomorrow stays the same...
