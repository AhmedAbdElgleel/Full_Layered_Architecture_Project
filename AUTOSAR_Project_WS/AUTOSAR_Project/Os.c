 /******************************************************************************
 *
 * Module: Os
 *
 * File Name: Os.c
 *
 * Description: Source file for Os Scheduler.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "Os.h"
#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Gpt.h"

/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmable Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm(" CPSIE I ")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmable Systems Exceptions and Faults by setting the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm(" CPSID I ")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm(" CPSIE F ")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm(" CPSID F ")

/* Global variable store the Os Time */
static uint8 g_Time_Tick_Count = 0;

/* Global variable to indicate the the timer has a new tick */
static uint8 g_New_Time_Tick_Flag = 0;

/*********************************************************************************************/
void Os_start(void)
{
    /* Global Interrupts Enable */
    Enable_Exceptions();

    /* Execute the Init Task */
    Init_Task();

    /*Enable Interrupt for Systick timer*/
    Gpt_EnableNotification(SYSTICK_TIMER);

    /*Start the Systick Timer*/
    Gpt_StartTimer(SYSTICK_TIMER, OS_BASE_TIME);

    /* Start the Os Scheduler */
    Os_Scheduler();
}

/*********************************************************************************************/
void Os_NewTimerTick(void)
{
    /* Increment the Os time by OS_BASE_TIME */
    g_Time_Tick_Count   += OS_BASE_TIME;

    /* Set the flag to 1 to indicate that there is a new timer tick */
    g_New_Time_Tick_Flag = 1;
}

/*********************************************************************************************/
void Os_Scheduler(void)
{
    while(1)
    {
	/* Code is only executed in case there is a new timer tick */
	if(g_New_Time_Tick_Flag == 1)
	{
	    switch(g_Time_Tick_Count)
            {
		case 20:
		case 100:
			    Button_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 40:
		case 80:
			    Button_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 60:
			    Button_Task();
			    App_Task();
			    g_New_Time_Tick_Flag = 0;
			    break;
		case 120:
			    Button_Task();
			    App_Task();
			    Led_Task();
			    g_New_Time_Tick_Flag = 0;
			    g_Time_Tick_Count = 0;
			    break;
		default:
		    break;
            }
	}
    }

}
/*********************************************************************************************/
