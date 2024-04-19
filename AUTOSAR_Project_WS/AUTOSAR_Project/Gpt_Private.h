/******************************************************************************
 *
 * Module: Gpt
 *
 * File Name: Gpt_Private.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Gpt Driver Registers and Private Macros
 *
 * Author: Ahmed AbdElgleel
 ******************************************************************************/

#ifndef GPT_PRIVATE_H_
#define GPT_PRIVATE_H_

#include "Gpt.h"
#include "Common_Macros.h"

/*this type is private for Gpt.c not in autosar docs to hold the dynamic configuration as following*/
typedef struct
{
    Gpt_StateType     gpt_channel_state;
    Gpt_InterruptOption Gpt_EnableChannelNotification;
    Gpt_InterruptOption gpt_wakeup_state;

}Gpt_DynamicConfigType;

/*Macros for Gpt Status*/
#define GPT_INITIALIZED                         (1U)
#define GPT_NOT_INITIALIZED                     (0U)

/* SysTick priority mask and position */
#define SYSTICK_PRIORITY_MASK                   0x1FFFFFFF
#define SYSTICK_PRIORITY_BITS_POS               29


/* Run mode clock control */
#define SYSCTL_RCGCTIMER_REG                    (*((volatile uint32 *)0x400FE604))
#define SYSCTL_RCGCWTIMER_REG                   (*((volatile uint32 *)0x400FE65C))

/* Sleep mode clock control */
#define SYSCTL_SCGCTIMER_REG                    (*((volatile uint32 *)0x400FE704))
#define SYSCTL_SCGCWTIMER_REG                   (*((volatile uint32 *)0x400FE75C))

/* SysTick Timer registers */
#define SYSTICK_CTRL_REG                        (*((volatile uint32 *)0xE000E010))
#define SYSTICK_RELOAD_REG                      (*((volatile uint32 *)0xE000E014))
#define SYSTICK_CURRENT_REG                     (*((volatile uint32 *)0xE000E018))
#define NVIC_EN0_REG                            (*((volatile uint32 *)0xE000E100))

/* System Control Block Registers */
#define NVIC_SYSTEM_PRI3_REG                    (*((volatile uint32 *)0xE000ED20))

/* SysTick control Register bits*/
#define ENABLE                                  0
#define INTEN_SYSTICK                           1
#define CLK_SRC                                 2
#define COUNT                                   6

/*NVIC Interrupt Enable bit for Systick*/
#define INTEN_NVIC                              15

#endif /* GPT_PRIVATE_H_ */
