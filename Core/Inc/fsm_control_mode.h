/*
 * fsm_control_mode.h
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */

#ifndef INC_FSM_CONTROL_MODE_H_
#define INC_FSM_CONTROL_MODE_H_

#include "main.h"


extern uint8_t State;

void fsm_control_mode();

 enum State_Mode {
     AUTO_MODE,
     CONFIG_RED_MODE,
     CONFIG_YELLOW_MODE,
     CONFIG_GREEN_MODE,
     MANUAL_MODE,
     RESET_MODE,
	 PEDESTIAN_MODE
 };

 extern enum State_Mode State;

#endif /* INC_FSM_CONTROL_MODE_H_ */
