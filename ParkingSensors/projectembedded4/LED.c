/*
 * LED.c
 *
 *  Created on: Oct 5, 2024
 *      Author: belal
 */
#include "LED.h"

/* Initializes LEDS*/
void LED_init(void){
	/*Sets up LEDS to outputs*/
	GPIO_setupPinDirection(LED_PORT_ID, LED_RED_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, LED_BLUE_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(LED_PORT_ID, LED_GREEN_PIN_ID, PIN_OUTPUT);
	/*Initializes them to zero*/
	GPIO_writePin(LED_PORT_ID, LED_RED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(LED_PORT_ID, LED_GREEN_PIN_ID, LOGIC_LOW);
	GPIO_writePin(LED_PORT_ID, LED_BLUE_PIN_ID, LOGIC_LOW);
}
void LED_on(LED_ID id){
	GPIO_writePin(LED_PORT_ID, id, LOGIC_HIGH); /*Turns on*/
}
void LED_off(LED_ID id){
	GPIO_writePin(LED_PORT_ID, id, LOGIC_LOW);/*Turns off*/
}

