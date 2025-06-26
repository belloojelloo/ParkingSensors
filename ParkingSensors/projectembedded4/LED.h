/*
 * LED.h
 *
 *  Created on: Oct 5, 2024
 *      Author: belal
 */

#ifndef LED_H_
#define LED_H_
#include "gpio.h"
#include "std_types.h"
#include "common_macros.h"

typedef unsigned char LED_ID;
#define LED_PORT_ID PORTC_ID
#define LED_RED_PIN_ID PIN0_ID
#define LED_GREEN_PIN_ID PIN1_ID
#define LED_BLUE_PIN_ID PIN2_ID
#define LED_ON LOGIC_HIGH



#if (LED_ON == LOGIC_HIGH)
#define LED_OFF LOGIC_LOW
#else
#define LED_OFF LOGIC_HIGH
#endif

void LED_init(void);
void LED_on(LED_ID id);
void LED_off(LED_ID id);
#endif /* LED_H_ */
