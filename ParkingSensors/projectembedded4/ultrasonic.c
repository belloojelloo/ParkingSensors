/*
 * ultrasonic.c
 *
 *  Created on: Oct 15, 2024
 *      Author: belal
 */

#include "ultrasonic.h"
#include <avr/io.h>
#include <util/delay.h>
uint8 edge = 0;
uint16 echohigh = 0;
uint16 echolow = 0;
uint16 echofinal = 0;

void Ultrasonic_init(void){

	ICU_ConfigType ICU_config = {F_CPU_8,RAISING};
	ICU_init(&ICU_config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(ULTRASONIC_ECHO_PORT_ID, ULTRASONIC_ECHO_PIN_ID, PIN_INPUT);

}
void Ultrasonic_Trigger(void){
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT_ID, ULTRASONIC_TRIGGER_PIN_ID, LOGIC_LOW);
}
uint16 Ultrasonic_readDistance(void){


    Ultrasonic_Trigger();
    while (edge != 0);

    uint16 distance;
    distance = (echofinal/117.6)+1;

    return distance;
}

void Ultrasonic_edgeProcessing(void){

    if (0 == edge){
    	echohigh =  ICU_getInputCaptureValue();
        ICU_setEdgeDetectionType(FALLING);
        edge = 1;
    }
    else if (1 == edge)
    {
        echolow = ICU_getInputCaptureValue();
        echofinal = echolow - echohigh;
        ICU_setEdgeDetectionType(RAISING);
        edge = 0;
    }
}
