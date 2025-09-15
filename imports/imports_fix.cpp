#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

struct ImportFix {
  const char *dllName;
  const char *functionName;
  DWORD targetAddress;
};

// Array of imports to fix
// Add new entries here: {"dll_name", "function_name", target_address}
ImportFix g_importFixes[] = {
    {"kernel32.dll", "GetVersionExA", 0x00bb0ef4},
    // Add more imports here as needed:
    // {"user32.dll", "MessageBoxA", 0x00bb0ef8},
    // {"advapi32.dll", "RegOpenKeyA", 0x00bb0efc},
};

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call,
                      LPVOID lpReserved) {
  switch (ul_reason_for_call) {
  case DLL_PROCESS_ATTACH: {
    FILE *logFile = fopen("import_fix.txt", "a");
    if (logFile != NULL) {
      time_t rawtime;
      struct tm *timeinfo;
      char timestamp[80];

      time(&rawtime);
      timeinfo = localtime(&rawtime);
      strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

      fprintf(logFile, "\n=== Import Fix Run - %s ===\n", timestamp);
      fflush(logFile);
    }

    int numFixes = sizeof(g_importFixes) / sizeof(ImportFix);
    int successCount = 0;
    int failureCount = 0;

    for (int i = 0; i < numFixes; i++) {
      ImportFix &fix = g_importFixes[i];

      HMODULE hDll = GetModuleHandleA(fix.dllName);
      if (hDll == NULL) {
        hDll = LoadLibraryA(fix.dllName);
        if (hDll == NULL) {
          failureCount++;
          if (logFile != NULL) {
            fprintf(logFile, "FAILED: %s::%s -> 0x%08lX (DLL not found)\n",
                    fix.dllName, fix.functionName, fix.targetAddress);
            fflush(logFile);
          }
          continue;
        }
      }

      FARPROC pFunction = GetProcAddress(hDll, fix.functionName);

      if (pFunction == NULL) {
        failureCount++;
        if (logFile != NULL) {
          fprintf(logFile, "FAILED: %s::%s -> 0x%08lX (Function not found)\n",
                  fix.dllName, fix.functionName, fix.targetAddress);
          fflush(logFile);
        }
        continue;
      }

      DWORD oldProtect;
      BOOL success = VirtualProtect((LPVOID)fix.targetAddress, sizeof(FARPROC),
                                    PAGE_READWRITE, &oldProtect);

      if (success) {
        *(FARPROC *)fix.targetAddress = pFunction;
        VirtualProtect((LPVOID)fix.targetAddress, sizeof(FARPROC), oldProtect,
                       &oldProtect);

        successCount++;
        if (logFile != NULL) {
          fprintf(logFile, "SUCCESS: %s::%s -> 0x%08lX (Address: 0x%08lX)\n",
                  fix.dllName, fix.functionName, fix.targetAddress,
                  (DWORD)pFunction);
          fflush(logFile);
        }
      } else {
        failureCount++;
        if (logFile != NULL) {
          fprintf(logFile,
                  "FAILED: %s::%s -> 0x%08lX (Memory protection failed)\n",
                  fix.dllName, fix.functionName, fix.targetAddress);
          fflush(logFile);
        }
      }
    }

    if (logFile != NULL) {
      fprintf(logFile, "--- Run Summary: %d successful, %d failed ---\n",
              successCount, failureCount);
      fclose(logFile);
    }

    break;
  }
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}

extern "C" {
__declspec(dllexport) void DummyImport() {
  // This function does nothing - it's just to satisfy the import table
  // DllMain will still run automatically when the DLL loads
}
}
