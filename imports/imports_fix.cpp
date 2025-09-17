#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <windows.h>

struct ImportFix {
  const char *dllName;
  const char *functionName;
  DWORD targetAddress;
};

struct AddressReset {
  DWORD targetAddress;
  DWORD resetValue;
};

// Array of imports to fix
// Add new entries here: {"dll_name", "function_name", target_address}
ImportFix g_importFixes[] = {
    {"kernel32.dll", "GetVersionExA", 0x00bb0ef4},
    {"kernel32.dll", "GetCommandLineA", 0x00BB0EF8},
    {"kernel32.dll", "GetModuleHandleA", 0x00BB0DF4},
    {"kernel32.dll", "IsBadWritePtr", 0x00BB0F0C},
    {"kernel32.dll", "IsBadReadPtr", 0x00BB0F80},
    {"kernel32.dll", "GetProcAddress", 0x00BB0E34},

    // Add more imports here as needed:
    // {"user32.dll", "MessageBoxA", 0x00bb0ef8},
    // {"advapi32.dll", "RegOpenKeyA", 0x00bb0efc},
};

// Array of addresses to reset
// Add new entries here: {target_address, reset_value}
AddressReset g_addressResets[] = {
    {0x00BAD868, 0x00000000},
    {0x00BADA20, 0x00000000},
    // Not sure about this one:
    {0x00BADA24, 0x00000000},
    {0x00A6323C, 0x00000000},
    {0x00a63218, 0x00000000},
    {0x00a6328c, 0x00000000},
    {0x00a63258, 0x00000000},

    // Add more address resets here as needed:
    // {0x00DEADBEEF, 0x12345678},
};

BOOL WriteProtectedMemory(LPVOID address, LPCVOID data, SIZE_T size) {
  DWORD oldProtect;
  BOOL success = VirtualProtect(address, size, PAGE_READWRITE, &oldProtect);

  if (success) {
    memcpy(address, data, size);
    VirtualProtect(address, size, oldProtect, &oldProtect);
  }

  return success;
}

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

      BOOL success = WriteProtectedMemory((LPVOID)fix.targetAddress, &pFunction,
                                          sizeof(FARPROC));

      if (success) {
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

    // Process address resets
    int numResets = sizeof(g_addressResets) / sizeof(AddressReset);
    int resetSuccessCount = 0;
    int resetFailureCount = 0;

    for (int i = 0; i < numResets; i++) {
      AddressReset &reset = g_addressResets[i];

      BOOL success = WriteProtectedMemory((LPVOID)reset.targetAddress,
                                          &reset.resetValue, sizeof(DWORD));

      if (success) {
        resetSuccessCount++;
        if (logFile != NULL) {
          fprintf(logFile, "RESET SUCCESS: 0x%08lX -> 0x%08lX\n",
                  reset.targetAddress, reset.resetValue);
          fflush(logFile);
        }
      } else {
        resetFailureCount++;
        if (logFile != NULL) {
          fprintf(
              logFile,
              "RESET FAILED: 0x%08lX -> 0x%08lX (Memory protection failed)\n",
              reset.targetAddress, reset.resetValue);
          fflush(logFile);
        }
      }
    }

    if (logFile != NULL) {
      fprintf(logFile,
              "--- Run Summary: %d imports successful, %d imports failed, %d "
              "resets successful, %d resets failed ---\n",
              successCount, failureCount, resetSuccessCount, resetFailureCount);
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
