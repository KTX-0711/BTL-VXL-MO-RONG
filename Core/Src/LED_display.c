/*
 * LED_display.c
 *
 *  Created on: Nov 21, 2025
 *      Author: nguye
 */

#include "main.h"
uint8_t count = 0;
void turn_off(){
	HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, RESET );
	HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, RESET );
}
void LED_display_NS(int count){
	    turn_off();
		HAL_GPIO_WritePin(A1_GPIO_Port, A1_Pin, (count%2) ? SET : RESET );
		HAL_GPIO_WritePin(B1_GPIO_Port, B1_Pin, (count/2) ? SET : RESET );
		count++;
		if (count >=4) count=0;

}

void LED_display_EW(int count){
     	turn_off();
		HAL_GPIO_WritePin(A2_GPIO_Port, A2_Pin, (count%2) ? SET : RESET );
		HAL_GPIO_WritePin(B2_GPIO_Port, B2_Pin, (count/2) ? SET : RESET );
		count++;
		if (count >=4) count=0;

}
