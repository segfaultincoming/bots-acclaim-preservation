# You wouldn't steal a DLL?

After well-deserved rest, aka doing what my wifu wants not what I want, I'm here!

## Always has been

I didn't want to manually build an import table, if that was not clear. So this has always been plan B. I've been researching different options on how to automate this. I've even considered building a tool for it, but it would've taken far too long.

Needless to say, I'm not experienced enough, so a fully automated solution is not viable for me. I want something that I can quickly test and change, if needed.

### You can't C me

How many missing addresses do we have? 10, 20, 50? If there's a way for me to add those in `C` or `C++`...

#### DLL Hijacking

You wouldn't steal a baby, but would you hijack a DLL? Hijacking DLLs is easy-peasy. The target executable needs `example.dll`? Well, you just place your own DLL, named `example.dll`, in its directory. Guess what's loaded?

You guessed right! MY `example.dll`. DLLs are not loaded by full path. `LoadLibrary('foo.dll')` will first look into the current directory and then everywhere else.

Note: Core system DLLs (KnownDLLs) such as `kernel32.dll` are always loaded from `System32` and cannot be hijacked this way.

```cpp
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD reason, LPVOID lpReserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        // I can do whatever I want here
    }

    return TRUE;
}

extern "C" {
    __declspec(dllexport) void dummy() {}
}
```

And then

```bash
clang++ -shared -o kernel32.dll kernel32.cpp kernel32.def
```

#### Just load it, really...

`DllMain` is automatically executed, when the DLL is loaded. Hence... just import a function from your DLL and you're golden!

The code is exactly the same as in the "hijacking" situation, but you could name your DLL whatever you want. Just use `CFF Explorer` to add an import to your DLL.

## Loading it is

My plan is simple. Find the missing imports, while researching the code in Ghidra, infer what they could be, fix the addresses.

I'm lucky! My first missing import is literally at OEP! YEY!

```asm
00759a76 | ff 15 f4 0e bb 00 | CALL dword ptr [DAT_00bb0ef4]
```

It's literally trying to dereference the pointer on `0x00bb0ef4` and call it. If you've been careful... the OEP is standard C++ runtime startup - it allocates memory, runs a few checks and then calls `WinMain`.

So, without unveiling details around my once-in-a-lifetime discovery, it's `GetVersionExA`.

So, let's try to fix it:

```cpp
// Load the DLL
HMODULE hDll = GetModuleHandleA("kernel32.dll");
// Get the function address
FARPROC pFunction = GetProcAddress(hDll, "GetVersionExA");
// Allow writing to the target address
DWORD oldProtect;
BOOL success = VirtualProtect((LPVOID)0x00bb0ef4, sizeof(FARPROC), PAGE_READWRITE, &oldProtect);
if (success) {
  // Patch the address
  *(FARPROC *)fix.targetAddress = pFunction;
  // We're good boiiis, we will restore the address protection
  VirtualProtect((LPVOID)0x00bbef4, sizeof(FARPROC), oldProtect,
}
```

### Ready, steady...

Wow, for the first time I'm able to debug further than OEP! But wait... I get a crash in `_CrtCheckMemory`? Did they... ship a debug build?

That would definitely explain all the path/file references that I've found.

## Tomorrow I show you

Research. Бетон. In my mind the unpacking stub has not only unpacked the executable, but also set up some global variables/structs.

I have a decision to make, before I dive deeper: Do I try to follow the whole unpacking stub or do I understand why the executable crashes?
