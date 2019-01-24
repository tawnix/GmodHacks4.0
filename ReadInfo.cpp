#include "ReadInfo.h"

void ReadMem::GetPlayerAddress()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.ClientModule + Offset.PlayerBase), &Entity.LocalPlayerBase, sizeof(DWORD), NULL);
}

void ReadMem::GetEntityAddress(int CurrentEntity)
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)((PI.ClientModule + Offset.EntityList) + (CurrentEntity * Offset.LoopDistance)), &Entity.EntityBase, sizeof(DWORD), NULL);
}

void ReadMem::GetEntityBoneAddress()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.EntityBase + Offset.BonesBase), &Entity.BonesBase, sizeof(DWORD), NULL);
}

void ReadMem::ReadLocalOrigin()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.LocalPlayerBase + Offset.VecOriginX), &MyCoords, sizeof(float[3]), NULL);
}

void ReadMem::ReadEyePos()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.LocalPlayerBase + Offset.EyePos), &MyEyePos.z, sizeof(float), NULL);

    MyEyePos.x = MyCoords.x;
    MyEyePos.y = MyCoords.y;
    MyEyePos.z = MyCoords.z + MyEyePos.z;
}

int ReadMem::ReadNumberOfPlayers()
{
    int Players = 0;
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.ClientModule + Offset.NumOfPlayers), &Players, sizeof(int), NULL);
    return Players;
}

void ReadMem::ReadVecAngles()
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.EngineModule + Offset.VecAngleX), &x, sizeof(float), NULL);
    ReadProcessMemory(PI.GameHandle, (LPVOID)(PI.EngineModule + Offset.VecAngleY), &y, sizeof(float), NULL);
}

void ReadMem::GetEnemyBonePos(int EnemyNumber)
{
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.BonesBase + 0x30 * 7 + Offset.BonesX), &EnemyBoneCoords[EnemyNumber].x, sizeof(float), NULL);
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.BonesBase + 0x30 * 7 + Offset.BonesY), &EnemyBoneCoords[EnemyNumber].y, sizeof(float), NULL);
    ReadProcessMemory(PI.GameHandle, (LPVOID)(Entity.BonesBase + 0x30 * 7 + Offset.BonesZ), &EnemyBoneCoords[EnemyNumber].z, sizeof(float), NULL);
}

void ReadMem::PrintTest()
{
    std::cout << "Eye x:" << MyEyePos.x << "\n";
    std::cout << "Eye y:" << MyEyePos.y << "\n";
    std::cout << "Eye z:" << MyEyePos.z << "\n";
    system("cls");
}
