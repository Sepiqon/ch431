
//  gcc  -o prog  -LC:\Users\RyZen\Desktop\ch431 CH341WriteI2C.c -lCH341DLL
#include <windows.h>
#include <CH341DLL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int *a = (int *)(CH341OpenDevice(0));
    printf("Hej %d", a);
    return 0;
}