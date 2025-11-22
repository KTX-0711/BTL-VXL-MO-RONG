/*
 * fsm_auto_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "fsm_auto_mode.h"

  int NS_time = 10;
  int EW_time = 10;

  uint8_t GREEN  = 3;
  uint8_t YELLOW = 2;
  uint8_t RED    = 5;
  uint8_t RED_ini    = 3  ;
  uint8_t GREEN_ini  = 2;
  uint8_t YELLOW_ini = 5;
void run_Auto(){
           // -------------NS---------------

	 if(State != AUTO_MODE) {
		 return;
	 }

  	 uint8_t cycle  = GREEN+YELLOW+RED;

     	if(NS_time < GREEN) {

     		display_LCD_NS("GREEN Time: ",NS_time);
     		LED_display_NS(2);
     	}

     	else if(NS_time < GREEN+YELLOW) {

     		display_LCD_NS("YELLOW time: ", cycle - NS_time);
     		LED_display_NS(1);

     	}

     	else if(NS_time < cycle) {

     		display_LCD_NS("RED time: ",cycle - NS_time);
      		LED_display_NS(3);

     	}


     	NS_time = (NS_time+1)%cycle;

     	// ----------------EW---------------------

     	if(EW_time < RED) {

     		display_LCD_EW("GREEN Time",EW_time);
     		LED_display_EW(2);

     	}

     	if(EW_time < RED+GREEN) {

     		display_LCD_EW("YELLOW time",cycle - EW_time);

     		LED_display_EW(1);

     	}

     	if(EW_time < cycle) {

     		display_LCD_EW("RED time",cycle - EW_time);
      		 LED_display_EW(3);
     	}

     	EW_time = (EW_time+1)%cycle;
}
