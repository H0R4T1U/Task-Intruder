#include "enum.hpp"




void printProcessInfo(DWORD ProcessId) {
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

	HANDLE hProcess = NULL;
	hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, ProcessId);
    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod),
            &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName,
                sizeof(szProcessName) / sizeof(TCHAR));
        }
        // Print the process name and identifier.

        _tprintf(TEXT("%s  (PID: %u)\n"), szProcessName, ProcessId);

        // Release the handle to the process.

        CloseHandle(hProcess);
    }

    
}
int enumerate() {
    DWORD processes[1024];
    DWORD bytecount;
	if (!EnumProcesses(processes, sizeof(processes), &bytecount)) {
		return 1;
	}
	DWORD nrProcesses = bytecount / sizeof(DWORD);
	for (int i = 0; i < nrProcesses; i++) {
		if (processes[i] != 0) {
			printProcessInfo(processes[i]);
		}
	}
    return 0;
}
