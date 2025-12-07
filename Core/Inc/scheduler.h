/*
 * scheduler.h
 *
 *  Created on: Nov 21, 2025
 *      Author: nguye
 */
#include "main.h"

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#define MAX_TASKS 20
typedef struct sTask{
	 struct sTask* next;
	 void ( * pTask) ( void ) ;
	 uint32_t Delay ;
	 uint32_t Period ;
	 uint8_t RunMe;
	 uint32_t TaskID ;
 } sTask;

 typedef enum{
 	ERROR_SCH_NORMAL = 0,
 	ERROR_SCH_TOO_MANY_TASKS,
 	ERROR_SCH_QUEUE_INITIALIZATION_FAILED,
 	ERROR_SCH_INVALID_TASK_INIT,
 	ERROR_SCH_CANNOT_DELETE_TASK,
 	ERROR_SCH_WAITING_FOR_SLAVE_TO_ACK,
 	ERROR_SCH_WAITING_FOR_START_COMMAND_FROM_MASTER,
 	ERROR_SCH_ONE_OR_MORE_SLAVES_DID_NOT_START,
 	ERROR_SCH_LOST_SLAVE,
 	ERROR_SCH_CAN_BUS_ERROR,
 	ERROR_I2C_WRITE_BYTE_AT24C64
 }ERROR_REPORT;

#define SCH_MAX_TASKS  40
#define NO_TASK_ID     0



unsigned char SCH_Add_Task( void (* pFunction)() , unsigned int DELAY,unsigned int PERIOD);
unsigned char SCH_Delete_Task( const char TASK_INDEX);
void SCH_Dispatch_Tasks( void );
void SCH_Update( void );
void SCH_Init (void);
void SCH_Go_To_Sleep(void);
void SCH_Report_Status ( void );

#endif /* INC_SCHEDULER_H_ */
