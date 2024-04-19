 /******************************************************************************
 *
 * Module: Mcu
 *
 * File Name: Mcu.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Mcu Driver
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "tm4c123gh6pm_registers.h"

void Mcu_Init(void)
{
    /* Enable clock for All PORTs and wait for clock to start */
    SYSCTL_RCGCGPIO_REG |= 0x3F;
    while(!(SYSCTL_PRGPIO_REG & 0x3F));
}
