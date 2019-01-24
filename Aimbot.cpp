#include "Aimbot.h"

void aimbot::AimBot(bool IsEnabled)
{
    ReadMemory.GetPlayerAddress();
    
    int Players = ReadMemory.ReadNumberOfPlayers();
    for (int i = 1; i < Players; i++)
    {
        ReadMemory.GetEntityAddress(i);
        ReadMemory.GetEntityBoneAddress();
        ReadMemory.ReadLocalOrigin();
        ReadMemory.ReadEyePos();
        ReadMemory.GetEnemyBonePos(i);
        
        ReadMemory.NewDistance = math.Get3DDistance(ReadMemory.EnemyBoneCoords[i], ReadMemory.MyEyePos);

        if (abs(ReadMemory.NewDistance) < abs(ReadMemory.OldDistance))
        {
            if (ReadMemory.NewDistance < 1) { continue; }
            else { ReadMemory.OldDistance = ReadMemory.NewDistance; closest = i; }
        }
    }
    
    ReadMemory.AngleToEnemy = math.CalcAngle(ReadMemory.MyEyePos, ReadMemory.EnemyBoneCoords[closest]);

    ReadMemory.ReadVecAngles();

    if (closest > 0)
    {
        WriteProcessMemory(ReadMemory.PI.GameHandle, (LPVOID)(ReadMemory.PI.EngineModule + ReadMemory.Offset.VecAngleX), &ReadMemory.AngleToEnemy.x, sizeof(float), NULL);
        WriteProcessMemory(ReadMemory.PI.GameHandle, (LPVOID)(ReadMemory.PI.EngineModule + ReadMemory.Offset.VecAngleY), &ReadMemory.AngleToEnemy.y, sizeof(float), NULL);
    }
}
