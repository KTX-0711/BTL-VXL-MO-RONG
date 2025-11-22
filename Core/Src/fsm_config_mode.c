/*
 * fsm_config_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */

#include "fsm_config_mode.h"
uint8_t incre = 0;

void signal_config(unsigned char color){

	if(color == 0 ){

 		LED_display_NS(3);
 		LED_display_EW(3);

	}

	if(color == 1) {
 		LED_display_EW(1);
 		LED_display_NS(1);
	}

	if(color == 2) {
	 	LED_display_EW(2);
	    LED_display_NS(2);
	}

}
void run_Config(unsigned char color ){

	if(State != CONFIG_RED_MODE &&State != CONFIG_YELLOW_MODE && State != CONFIG_GREEN_MODE ) {
			 return;
		 }
	signal_config(color);


	if(CheckButton(1)){
		incre++;
	}
	else if(CheckButton_1s(0)){
		incre += 5;
	}

	incre = incre%100;

	if(CheckButton(2)){

	if(color == 0){

		RED+= incre;

	}

	if(color == 1){

		YELLOW+=incre;
	}

	if(color == 2){
		GREEN+=incre;
	}


	if( GREEN + YELLOW > 99){

		run_Reset();

	}

	}

}



