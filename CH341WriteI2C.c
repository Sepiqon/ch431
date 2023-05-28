
//  gcc  -o prog  -LC:\Users\RyZen\Desktop\ch431 CH341WriteI2C.c -lCH341DLL
#include <windows.h>
#include <CH341DLL.h>
#include <stdio.h>

int main(int argc, char* argv[])
{

    int* open = (int*)(CH341OpenDevice(0));
    if (open == -1) {
        printf("[ERROR] Nie znaleziono urzadzenia CH341.\n");
        return 1;
    }
    else {
        printf("[INFO] Programator CH341 zostal odnaleziony.\n");
    }
    boolean res = CH341ResetDevice(0);
    if (!res) {
        printf("[ERROR] Reset sie nie powiodl.\n");
        return 1;
    }
    else {
        printf("[INFO] Wykonano reset.\n");
    }
    boolean i2cStarts = CH341SetStream(0, 0);
    if (!i2cStarts) {
        printf("[ERROR] Magistrala I2C sie nie uruchomila.\n");
        return 1;
    }
    else {
        printf("[INFO] Magistrala I2C dziala.\n");
    }
    CH341SetStream(0, 0);
    UINT8 tosend[] = { (0x08 << 1), 84, 97, 106, 110, 121, 32, 116, 101, 107, 115, 116, 32, 110, 119, 109, 32, 99, 122, 121, 32, 115, 105, 101, 32, 117, 100, 97, 32, 112, 111, 119, 111, 100, 122, 101, 110, 105, 97, 32, 58, 41, 33 };
    UINT8 toread[] = { 0x00 };
    boolean test1 = CH341StreamI2C(0, 32, &tosend[0], 0, NULL);
    if (test1) {
        printf("UDALO SIE\n");
    }

    printf("Hej %d NACISNIJ KLAWISZ BY ZAKONCZYC...", open);
    getchar();
    return 0;
}