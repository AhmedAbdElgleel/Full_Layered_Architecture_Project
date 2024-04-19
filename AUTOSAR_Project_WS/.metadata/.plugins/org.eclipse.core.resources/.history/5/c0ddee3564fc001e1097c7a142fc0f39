/******************************************************************************
 *
 * Module: Application
 *
 * File Name: App.c
 *
 * Description: Source file for Application Tasks.
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#include "App.h"
#include "Button.h"
#include "Led.h"
#include "Dio.h"
#include "Mcu.h"

/* Description: Task executes once to initialize all the Modules */
void Init_Task(void)
{
    /* Initialize Mcu Driver */
    Mcu_Init();

    /* Initialize Dio Driver */
    Dio_Init(&Dio_Configuration);

    /* Initialize LED Driver */
    Led_Init();

    /* Initialize Button Driver */
    Button_Init();
}

/* Description: Task executes every 20 Mili-seconds to check the button state */
void Button_Task(void)
{
    Button_RefreshState();
}

/* Description: Task executes every 40 Mili-seconds to refresh the LED */
void Led_Task(void)
{
    Led_RefreshOutput();
}

/* Description: Task executes every 60 Mili-seconds to get the button status and toggle the led */
void App_Task(void)
{
    static uint8 button_previous_state = BUTTON_RELEASED;
    static uint8 button_current_state  = BUTTON_RELEASED;

    button_current_state = Button_GetState(); /* Read the button state */

    /* Only Toggle the led in case the current state of the switch is pressed
     * and the previous state is released */ 
    if((button_current_state == BUTTON_PRESSED) && (button_previous_state == BUTTON_RELEASED))
    {
        Led_Toggle();
    }

    button_previous_state = button_current_state;
}
