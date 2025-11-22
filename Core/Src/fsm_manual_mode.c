/*
 * fsm_manual_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */

#include "fsm_manual_mode.h"
uint8_t C = 0;
void run_Manual(){

	if(CheckButton(1)){

		turn_off();

		if(C == 0){
			LED_display_NS(3);
			LED_display_EW(2);

		}

		if(C == 1) {

			LED_display_NS(3);
		    LED_display_EW(1);

		}

		if(C==2){

			LED_display_NS(2);
			LED_display_EW(3);
		}

		if(C == 3){

			LED_display_NS(1);
			LED_display_EW(3);

		}

	 C = (C+1)%4;
	}



}
