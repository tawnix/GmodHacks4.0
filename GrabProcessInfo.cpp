#include "GrabProcessInfo.h"

void ProccessInformation::GrabEngineDll(char * ModuleName)
{
    HANDLE HandleSnap{ INVALID_HANDLE_VALUE };
    HandleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);

    if (HandleSnap == INVALID_HANDLE_VALUE) { std::cout << "Cannot obtain handle for engine.dll"; }

    Module.dwSize = sizeof(MODULEENTRY32);

    if (!Module32First(HandleSnap, &Module)) { CloseHandle(HandleSnap); }

    do 
    {
        if (!strcmp(Module.szModule, ModuleName))
        {
            CloseHandle(HandleSnap);
            EngineModule = (DWORD)Module.modBaseAddr;
        }

    } while (Module32Next(HandleSnap, &Module));
}

void ProccessInformation::GrabClientDll(char * ModuleName)
{
    PROCESSENTRY32 Process;
    Process.dwSize = sizeof(PROCESSENTRY32);

    HANDLE ProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
    if (ProcessSnapshot == INVALID_HANDLE_VALUE) { std::cout << "Cannot obtain snapshot of process\n"; }

    Process32First(ProcessSnapshot, &Process);

    if (!strcmp("hl2.exe", Process.szExeFile))
    {
        CloseHandle(ProcessSnapshot);
        ProcessID = Process.th32ProcessID;
    }

    while (Process32Next(ProcessSnapshot, &Process)) 
    {
        if (!strcmp("hl2.exe", Process.szExeFile))
        {
            CloseHandle(ProcessSnapshot);
            ProcessID = Process.th32ProcessID;
        }
    }

    GameHandle = OpenProcess(PROCESS_ALL_ACCESS, NULL, ProcessID);

    ProcessSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);
    if (ProcessSnapshot == INVALID_HANDLE_VALUE) { std::cout << "Cannot create snapshot2\n"; }
    Module.dwSize = sizeof(MODULEENTRY32);

    if (!Module32First(ProcessSnapshot, &Module)) { CloseHandle(ProcessSnapshot); }
    do
    {
        if (!strcmp(Module.szModule, ModuleName))
        {
            CloseHandle(ProcessSnapshot);
            ClientModule = (DWORD)Module.modBaseAddr;
        }
    } while (Module32Next(ProcessSnapshot, &Module));
}


