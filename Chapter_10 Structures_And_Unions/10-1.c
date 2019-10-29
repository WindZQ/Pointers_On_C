#include <stdio.h>

typedef struct
{
    unsigned char area[5];
    unsigned char exchange[10];
    unsigned char station[10];
}TelphoneNumber;

typedef struct
{
    unsigned char data[10];
    unsigned char time[10];
    TelphoneNumber UserTelphone;
    TelphoneNumber CallTelphone;
    TelphoneNumber PayTelphon;
}Telphone_Call;

int main()
{
    return 0;
}
