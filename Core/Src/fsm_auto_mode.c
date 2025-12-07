/*
 * fsm_auto_mode.c
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */
#include "fsm_auto_mode.h"

  int NS_time = 0;
  int EW_time = 0;

  uint8_t GREEN  = 3;
  uint8_t YELLOW = 2;
  uint8_t RED    = 5;
  uint8_t RED_ini    = 3  ;
  uint8_t GREEN_ini  = 2;
  uint8_t YELLOW_ini = 5;

  void run_Auto()
  {
      if (State != AUTO_MODE) return;

      uint8_t cycle = GREEN + YELLOW + RED;

      int NS_show = 0, EW_show = 0;
      char *NS_label, *EW_label;

      // --------- NS ----------
      if (NS_time < GREEN) {
          NS_label = "NS G: ";
          NS_show  = GREEN - NS_time;
          LED_display_NS(2);
      }
      else if (NS_time < GREEN + YELLOW) {
          NS_label = "NS Y: ";
          NS_show  = GREEN + YELLOW - NS_time;
          LED_display_NS(1);
      }
      else {
          NS_label = "NS R: ";
          NS_show  = cycle - NS_time;
          LED_display_NS(3);
      }

      // --------- EW ----------
      if (EW_time < RED) {
          EW_label = "EW R: ";
          EW_show  = RED - EW_time;
          LED_display_EW(3);
      }
      else if (EW_time < RED + GREEN) {
          EW_label = "EW G: ";
          EW_show  = RED + GREEN - EW_time;
          LED_display_EW(2);
      }
      else {
          EW_label = "EW Y: ";
          EW_show  = cycle - EW_time;
          LED_display_EW(1);
      }

      // --------- HIỂN THỊ LCD ----------
      display_LCD_NS(NS_label, NS_show, EW_label, EW_show);

      // --------- TĂNG THỜI GIAN -------------
      NS_time = (NS_time + 1) % cycle;
      EW_time = (EW_time + 1) % cycle;
  }
