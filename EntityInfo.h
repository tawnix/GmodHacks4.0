#pragma once
#include <Windows.h>


struct Vec3
{
   float x, y, z;
};

struct EntityInfo
{
    // LocalPlayer Address
    DWORD LocalPlayerBase;
    DWORD EntityBase;
    DWORD BonesBase;



    // Players Information
    int Health{ 0 };
    int TeamNumber{ 0 };

};
