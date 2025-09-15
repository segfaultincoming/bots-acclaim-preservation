@echo off
echo Building version_hook.dll as x86 (32-bit) with clang...
clang -m32 -shared -o imports_fix.dll imports_fix.cpp -lkernel32
echo Build complete!
