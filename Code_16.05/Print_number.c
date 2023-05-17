#include <stdio.h>
#include <stdint.h>

void readbyte(uint8_t byte)
{   
    uint8_t temp = 0b10000000;
    int i;
    for (i = 0; i < 8; i++)
    {
        uint8_t result = temp & byte;
        if ( result == 0)
        {
            printf("0");
        }
        else 
        {
            printf("1");
        }
        byte <<= 1;
    }
}

int main ()
{   
    uint8_t n;
    printf("Number = ");
    scanf("%d", &n);
    printf("0b");
    readbyte(n);
    return 0;
}
