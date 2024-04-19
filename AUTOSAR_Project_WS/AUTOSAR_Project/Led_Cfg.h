/******************************************************************************
 *
 * Module: Led
 *
 * File Name: Led_Cfg.h
 *
 * Description: Header file for Pre-Compiler configuration used by Led Module
 *
 * Author: Mohamed Tarek
 ******************************************************************************/

#ifndef LED_CFG_H_
#define LED_CFG_H_

/* Set the led ON/OFF according to its configuration Positive logic or negative logic */
#define LED_ON          STD_HIGH
#define LED_OFF         STD_LOW

/* Set the LED Port */
#define LED_PORT        DioConf_LED1_PORT_NUM

/* Set the LED Pin Number */
#define LED_PIN_NUM     DioConf_LED1_CHANNEL_NUM

#endif /* LED_CFG_H_ */
