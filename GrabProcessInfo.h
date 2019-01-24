#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>


class ProccessInformation
{
public:
    DWORD ProcessID         { 0 };
    DWORD EngineModule      { 0 };
    DWORD ClientModule      { 0 };

    MODULEENTRY32 Module    { 0 };
    
    HANDLE GameHandle       { 0 };


    ProccessInformation()
    {
        GrabClientDll((char*)"client.dll");
        GrabEngineDll((char*)"engine.dll");
    }


    void GrabEngineDll(char* ModuleName);
    void GrabClientDll(char* ModuleName);
};

