/*
 * fsm_control_mode.c
 */

#include "main.h"

enum State_Mode State = AUTO_MODE;
uint8_t prev;
void fsm_control_mode() {
    switch (State) {
        case AUTO_MODE:
           // display_LCD_Mode("AUTO MODE", -1);
            if (CheckButton(0)) {
                State = CONFIG_RED_MODE;
            }
            break;

        case CONFIG_RED_MODE:
            //display_LCD_Mode("CONFIG RED", -1);
            if (CheckButton(0)) {
                State = CONFIG_YELLOW_MODE;
            }
            break;

        case CONFIG_YELLOW_MODE:
           // display_LCD_Mode("CONFIG YELLOW", -1);
            if (CheckButton(0)) {
                State = CONFIG_GREEN_MODE;
            }
            break;

        case CONFIG_GREEN_MODE:
            //display_LCD_Mode("CONFIG GREEN", -1);
            if (CheckButton(0)) {
                State = MANUAL_MODE;
            }
            break;

        case MANUAL_MODE:
            display_LCD_Mode("MANUAL", -1);
            if (CheckButton(0)) {
                State = AUTO_MODE;  // Reset về AUTO
            }
            break;

        case RESET_MODE:
            if (CheckButton_1s(0)) {
                State = AUTO_MODE;
            }
            break;

        default:
            State = AUTO_MODE;
            break;
    }
}
