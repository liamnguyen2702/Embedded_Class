#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00000000;
uint8_t PORTB = 0b11111111;

void readbyte(uint8_t byte)
{
    printf("0b");
    uint8_t temp;
    uint8_t i;
    for (i = 0; i < 8; i++)
    {
        temp = byte & 0b10000000;
        if (temp == 0)
        printf("0"); 
        else
        printf("1");
        byte <<= 1;
    } printf("\n");
}

typedef enum {
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7
}pins;

typedef enum{
    LOW,
    HIGH
}statuses;

void pinHigh(pins pin)
{
    PORTA = PORTA | (0x80 >> pin);
}

void pinLow(pins pin)
{
    PORTB = PORTB & ~ (128 >> pin);
}

void digitalWrite(pins pin, statuses status)
{
    if (status == HIGH)
    PORTA = PORTA | (0x80 >> pin);
    else
    PORTA = PORTA & ~ (0X80 >> pin);
}

int main()
{
    // pinHigh(PIN4);
    // pinHigh(PIN1);
    // pinHigh(PIN0);

    // readbyte(PORTA);


    // pinLow(PIN7);

    // readbyte(PORTB);


    digitalWrite(PIN7, HIGH);
    digitalWrite(PIN3, HIGH);

    readbyte(PORTA);

}
