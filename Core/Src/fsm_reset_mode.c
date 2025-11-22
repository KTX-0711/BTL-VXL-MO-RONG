/*
 * fsm_reset_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "main.h"

void run_Reset(){
	if(State != RESET_MODE) {
		return;
    }
	if(CheckButton(3)){

	  GREEN  = GREEN_ini;
	  YELLOW = YELLOW_ini;
   	  RED    = RED_ini;
	}
	State = AUTO_MODE;
}
