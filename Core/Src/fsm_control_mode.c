/*
 * fsm_control_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "main.h"

uint8_t State = AUTO_MODE;

void fsm_control_mode(){

	switch (State){

	case AUTO_MODE:

		if(CheckButton(0)){
			State = CONFIG_RED_MODE;
			run_Auto();
		}

			  break;

	case CONFIG_RED_MODE:

			if(CheckButton(0)){
				State = CONFIG_YELLOW_MODE;
				//run_Config(0);
			}
				break;

	case CONFIG_YELLOW_MODE:

				if(CheckButton(0)){
					State = CONFIG_GREEN_MODE;
					//run_Config(1);
				}
					break;

	case CONFIG_GREEN_MODE:

				if(CheckButton(0)){
					State = MANUAL_MODE;
				//	run_Config(2);
				}
					break;

	case MANUAL_MODE:

			if(CheckButton(0)){
				State = RESET_MODE;
				// run_Manual();
			}
				break;

	case RESET_MODE:
			if(CheckButton(0)){
				State = AUTO_MODE;
			//	run_Reset();
			}
			break;


	}

	if(CheckButton(2)){

		State = AUTO_MODE;

	}

}

