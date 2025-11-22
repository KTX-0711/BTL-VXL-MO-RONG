/*
 * LCD_display.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "main.h"

char TIME[2];
void display_LCD_NS(char* str, uint8_t time){
	 lcd_init();
	 lcd_goto_XY(0, 1);

	 itoa(time, TIME, 10);
	 strcat(str,TIME);
	 lcd_send_string(str);
}


void display_LCD_EW(char* str, uint8_t time){
	 lcd_init();
	 lcd_goto_XY(0, 1);

	 itoa(time, TIME, 10);
	 strcat(str,TIME);
	 lcd_send_string(str);
}
