#include "MathCalculations.h"

float Math::Get3DDistance(Vec3 BonePos, Vec3 EyePos)
{
    float x1, y1, z1;

    x1 = pow(BonePos.x - EyePos.x, 2.0);
    y1 = pow(BonePos.y - EyePos.y, 2.0);
    z1 = pow(BonePos.z - EyePos.z, 2.0);

    float value = x1 + y1 + z1;
    float distance = sqrt(value);
 
    return distance;
}

Vec3 Math::CalcAngle(Vec3 Src, Vec3 Dir)
{
    Vec3 AngleHolder;

    AngleHolder.x = Dir.x - Src.x;
    AngleHolder.y = Dir.y - Src.y;
    AngleHolder.z = Dir.z - Src.z;
    float Magnitude = sqrt(AngleHolder.x * AngleHolder.x + AngleHolder.y * AngleHolder.y + AngleHolder.z * AngleHolder.z);

    Vec3 AngleToEntity;
    AngleToEntity.y = atan2(AngleHolder.y, AngleHolder.x) * 180 / 3.14;
    AngleToEntity.x = -atan2(AngleHolder.z, Magnitude) * 180 / 3.14;
    AngleToEntity.z = 0.0;


    return AngleToEntity;
}

