/*
 * scheduler.h
 *
 *  Created on: Nov 21, 2025
 *      Author: nguye
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define MAX_TASKS 20
#define TICK 10 // ms
#include "main.h"
typedef struct {
    void (*pTask)(void);
    uint32_t Delay;
    uint32_t Period;
    uint32_t RunMe;
    uint32_t TaskID;

    uint32_t NextRunTime;
} sTask;


void SCH_Init(void);
void SCH_Update(void);
void SCH_Dispatch_Tasks(void);
uint32_t SCH_Add_Task(void (*pF)(void), uint32_t DELAY, const uint32_t PERIOD);
uint8_t SCH_Delete_Task(uint32_t TaskID);

#endif /* INC_SCHEDULER_H_ */
