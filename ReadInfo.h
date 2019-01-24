#pragma once
#include <Windows.h>
#include "EntityInfo.h"
#include "Offsets.h"
#include "GrabProcessInfo.h"


class ReadMem
{
public:
    ProccessInformation PI;
    Offsets Offset;
    EntityInfo Entity;

    // Vectors for the Aimbot
    Vec3 MyCoords;
    Vec3 MyEyePos;
    Vec3 EnemyBoneCoords[60];
    Vec3 AngleToEnemy;
    float x, y;
    float NewDistance = 0.0;
    float OldDistance = 999999.0;
    

    void GetPlayerAddress();
    void GetEntityAddress(int CurrentEntity);
    void GetEntityBoneAddress();
    void ReadLocalOrigin();
    void ReadEyePos();
    int ReadNumberOfPlayers();
    void ReadVecAngles();
    void GetEnemyBonePos(int EnemyNumber);
    void PrintTest();




};





