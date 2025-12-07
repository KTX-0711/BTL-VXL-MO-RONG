/*
 * fsm_config_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */

#include "fsm_config_mode.h"
uint8_t incre = 0;
uint8_t cnt = 1;
char check = 0;
void signal_config( ){

	if(--cnt == 0){
	    check = !check;

	    switch(State){
	        case CONFIG_RED_MODE:
	            check ? LED_display_NS(3) : turn_off_NS();
	            check ? LED_display_EW(3) : turn_off_EW();


	            break;

	        case CONFIG_YELLOW_MODE:
	            check ? LED_display_NS(1) : turn_off_NS();
	            check ? LED_display_EW(1) : turn_off_EW();

	            break;

	        case CONFIG_GREEN_MODE:
	            check ? LED_display_NS(2) : turn_off_NS();
	            check ? LED_display_EW(2) : turn_off_EW();

	            break;
	    }

	    cnt = 1;
	}

}
void run_Config(){

	if(State != CONFIG_RED_MODE &&State != CONFIG_YELLOW_MODE && State != CONFIG_GREEN_MODE ) {
			 return;
		 }

	if(CheckButton(1)){
		incre++;
		  if (incre > 99) incre = 1;


	}
	else if(CheckButton_1s(1)){
		incre += 5;
		  if (incre > 99) incre = 1;

	}


	if(State == CONFIG_RED_MODE){
	   display_LCD_Mode("CF RED: ", incre);
	}

	if(State == CONFIG_YELLOW_MODE){
		display_LCD_Mode("CF YELLOW: ", incre);
	}

	if(State == CONFIG_GREEN_MODE){
		 display_LCD_Mode("CF GREEN: ", incre);
	}



	if(CheckButton(2)){

		if(State == CONFIG_RED_MODE){
			RED = incre;


		}

		if(State == CONFIG_YELLOW_MODE){
			YELLOW = incre;

		}

		if(State == CONFIG_GREEN_MODE){
			GREEN=incre;

		}


		if( GREEN + YELLOW > 99){

			run_Reset();

		}

		else if (GREEN +YELLOW != RED){

			RED = GREEN + YELLOW;
		}

		incre = 0;


	}

}



