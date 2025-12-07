/*
 * LCD_display.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "main.h"

char buffer[17];     // buffer để ghép chuỗi (LCD 16x2)
int time1;    // số tới 3 ký tự
int time2;


uint8_t len1 = 0;
uint8_t len2 =0;
uint8_t len3 = 0;


void display_LCD_NS(char *labelNS, int timeNS, char *labelEW, int timeEW)
{
    // ----- Dòng 1: NS -----
	if(len1 != strlen(labelNS))
	lcd_init();

    lcd_goto_XY(1, 0);

    if (timeNS == -1)
        sprintf(buffer, "%s  ", labelNS);
    else
        sprintf(buffer, "%s%02d", labelNS, timeNS);

    lcd_send_string(buffer);


    // ----- Dòng 2: EW -----
    lcd_goto_XY(0, 1);

    if (timeEW == -1)
        sprintf(buffer, "%s  ", labelEW);
    else
        sprintf(buffer, "%s%02d", labelEW, timeEW);
    lcd_send_string(buffer);
    len1 = strlen(labelNS);

}


void display_LCD_Mode(char *label, int time) {
	if(len2  != strlen(label))
	lcd_init();

    lcd_goto_XY(1, 1);

    int time1 = time / 10;
    int time2 = time % 10;

    if (time == -1) {
        sprintf(buffer, "%s  ", label);
    } else {
        sprintf(buffer, "%s%d%d", label, time1, time2);
    }

    lcd_send_string(buffer);
    len2 =  strlen(label);

}









