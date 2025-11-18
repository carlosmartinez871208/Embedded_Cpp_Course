#include "fw.h"

void OS_Periodic_25mS       (void)
{
    GPIO_Base[1]->odr ^= GPIO_1Bit_control[3][1]; // Toggle PB3
}

void OS_Periodic_100mS       (void)
{
    GPIO_Base[1]->odr ^= GPIO_1Bit_control[4][1]; // Toggle PB4
}

void OS_Periodic_250mS       (void)
{
    GPIO_Base[1]->odr ^= GPIO_1Bit_control[5][1]; // Toggle PB5
}

void OS_Periodic_500mS       (void)
{
    GPIO_Base[1]->odr ^= GPIO_1Bit_control[6][1]; // Toggle PB6
}

void OS_Periodic_1S         (void)
{
    GPIO_Base[1]->odr ^= GPIO_1Bit_control[7][1]; // Toggle PB7
}