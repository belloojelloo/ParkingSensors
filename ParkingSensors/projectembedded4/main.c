/*
 * main.c
 *
 *  Created on: Oct 15, 2024
 *      Author: Belal Ramadan
 */

#include "LED.h"
#include "lcd.h"
#include "buzzer.h"
#include "ultrasonic.h"
#include "icu.h"
#include <util/delay.h>
#include <avr/io.h>

// Flag to track if the object is too close
uint8 tooclose = 0;

/*
 * Function: carSensor
 * -------------------
 * Measures distance using ultrasonic sensor and reacts based on proximity.
 * Controls LEDs, buzzer, and LCD display accordingly.
 */
void carSensor(void){
	uint16 distance = Ultrasonic_readDistance();

	if(tooclose == 0){
		// Display distance when object is not too close
		if(distance < 10){
			LCD_displayStringRowColumn(0, 0, "Distance=");
			LCD_moveCursor(0, 9);
			LCD_intgerToString(distance);
			LCD_moveCursor(0, 10);
			LCD_displayString(" ");
		}
		else{
			LCD_displayStringRowColumn(0, 0, "Distance=");
			LCD_moveCursor(0, 9);
			LCD_intgerToString(distance);
		}

		Buzzer_off();

		// Object dangerously close (≤ 5 cm)
		if(distance <= 5){
			tooclose = 1;
			LCD_clearScreen();
			return;
		}
		// Close range (6–10 cm): All LEDs on
		else if(distance >= 6 && distance <= 10){
			LED_on(LED_RED_PIN_ID);
			LED_on(LED_BLUE_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			Buzzer_off();
			return;
		}
		// Mid range (11–15 cm): Red and Green LEDs on
		else if(distance >= 11 && distance <= 15){
			LED_on(LED_RED_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			Buzzer_off();
			return;
		}
		// Safe range (16–20 cm): Only Red LED on
		else if(distance >= 16 && distance <= 20){
			LED_on(LED_RED_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			Buzzer_off();
			return;
		}
		// No object detected: All indicators off
		else{
			Buzzer_off();
			LED_off(LED_RED_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			return;
		}
	}
	else{
		// Object previously detected very close
		distance = Ultrasonic_readDistance();
		if(distance <= 5){
			LCD_displayStringRowColumn(0, 0, "STOP!");
			Buzzer_on();

			// Blink all LEDs as warning
			LED_on(LED_RED_PIN_ID);
			LED_on(LED_BLUE_PIN_ID);
			LED_on(LED_GREEN_PIN_ID);
			_delay_ms(700);
			LED_off(LED_RED_PIN_ID);
			LED_off(LED_BLUE_PIN_ID);
			LED_off(LED_GREEN_PIN_ID);
			_delay_ms(700);
			return;
		}
		else{
			// Object moved away — reset flag and clear screen
			tooclose = 0;
			LCD_clearScreen();
		}
	}
}

/*
 * Function: main
 * --------------
 * Initializes peripherals and continuously checks distance via carSensor.
 */
int main(void){
	LED_init();
	LCD_init();
	Buzzer_init();
	Ultrasonic_init();

	// Enable global interrupts
	SREG |= (1<<7);

	while(1){
		carSensor();
	}
}
