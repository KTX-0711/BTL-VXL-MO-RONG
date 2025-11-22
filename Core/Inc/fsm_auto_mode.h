/*
 * fsm_auto_mode.h
 *
 *  Created on: Nov 22, 2025
 *      Author: admin
 */

#ifndef INC_FSM_AUTO_MODE_H_
#define INC_FSM_AUTO_MODE_H_

#include "main.h"

extern uint8_t RED_ini    ;
extern uint8_t GREEN_ini  ;
extern uint8_t YELLOW_ini ;

extern uint8_t GREEN;
extern uint8_t YELLOW;
extern uint8_t RED;
extern int NS_time;
extern int EW_time;

void run_Auto();



#endif /* INC_FSM_AUTO_MODE_H_ */
