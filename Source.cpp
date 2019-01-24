#include "Aimbot.h"




int main()
{
    aimbot a;
    while (!GetAsyncKeyState(VK_F6))
    {
        while (GetAsyncKeyState(VK_XBUTTON2))
        {
            a.AimBot(true);
            Sleep(5);
        }
    }
    system("pause");

}