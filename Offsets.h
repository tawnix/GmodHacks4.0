#pragma once
#include <Windows.h>


struct Offsets
{
    const DWORD BonesX      { 0x0C };
    const DWORD BonesY      { 0x1C };
    const DWORD BonesZ      { 0x2C };
    const DWORD BonesBase   { 0x13E8 };
    const DWORD EyePos      { 0xF0 };
    const DWORD LoopDistance{ 0x10 };

    // Base addresses
    const DWORD EntityList  { 0x67ED34 };
    const DWORD PlayerBase  { 0x662EF4 };
    const DWORD NumOfPlayers{ 0x65E954 };


    // Angle Addresses
    const DWORD VecAngleX   { 0x4E05F4 };
    const DWORD VecAngleY   { 0x4E05F8 };

    //Players Offsets
    const DWORD VecOriginX  { 0x260 };
    const DWORD VecOriginY  { 0x264 };
    const DWORD VecOriginZ  { 0x268 };
    const DWORD Health      { 0x90 };
    const DWORD TeamNum     { 0x9C };
};
