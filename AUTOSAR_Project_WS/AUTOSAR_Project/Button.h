/******************************************************************************
 *
 * Module: Button
 *
 * File Name: Button.h
 *
 * Description: Header file for Button Module.
 *
 * Author: Ahmed AbdElgleel
 ******************************************************************************/
#ifndef BUTTON_H
#define BUTTON_H

#include "Std_Types.h"
#include "Button_Cfg.h"

/* Description: Read the Button state Pressed/Released */
uint8 Button_GetState(void);

/* 
 * Description: This function is called every 20ms by Os Task and it responsible for Updating 
 *              the BUTTON State. it should be in a PRESSED State if the button is pressed for 60ms.
 *		        and it should be in a RELEASED State if the button is released for 60ms.
 */   
void Button_RefreshState(void);

#endif /* BUTTON_H */
