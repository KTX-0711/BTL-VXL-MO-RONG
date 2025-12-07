#include "scheduler.h"
#include <stdlib.h>

sTask* head = NULL;
unsigned char size = 0;
unsigned char Error_code_G;
uint32_t delta_time = 0;

void SCH_Init(void){
    sTask* temp;
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
    head = NULL;
    size = 0;
    Error_code_G = ERROR_SCH_NORMAL;
}

unsigned char SCH_Add_Task(void (*pFunction)(), unsigned int DELAY, unsigned int PERIOD){

    delta_time = 0;

    if(size >= SCH_MAX_TASKS){
        Error_code_G = ERROR_SCH_TOO_MANY_TASKS;
        return SCH_MAX_TASKS;
    }

    sTask* insert = (sTask*) malloc(sizeof(sTask));
    if(insert == NULL){
        return SCH_MAX_TASKS;
    }

    insert->pTask = pFunction;
    insert->Delay = DELAY;
    insert->Period = PERIOD;
    insert->RunMe = 0;
    insert->TaskID = size;
    insert->next = NULL;

    if(head == NULL){
        head = insert;
        size++;
        return insert->TaskID;
    }

    if(DELAY < head->Delay){
        insert->next = head;
        head->Delay -= DELAY;
        head = insert;
        size++;
        return insert->TaskID;
    }

    sTask* p = head;
    sTask* prev = NULL;
    while(p){
        delta_time += p->Delay;
        if(delta_time > DELAY){
            insert->Delay = DELAY - (delta_time - p->Delay);
            insert->next = p;

            if(prev != NULL){
                prev->next = insert;
            }
            p->Delay -= insert->Delay;

            size++;
            return insert->TaskID;
        }
        prev = p;
        p = p->next;
    }

    // insert at end
    if(prev != NULL){
        insert->Delay = DELAY - delta_time;
        prev->next = insert;
        size++;
    }

    return insert->TaskID;
}

unsigned char SCH_Delete_Task(const char TASK_INDEX){
    if(head == NULL || size == 0 || TASK_INDEX >= size){
        Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
        return Error_code_G;
    }

    sTask* p = head;
    sTask* prev = NULL;
    unsigned char idx = 0;

    while(p){
        if(idx == TASK_INDEX){
            if(prev == NULL){
                // deleting head
                head = p->next;
            } else {
                prev->next = p->next;
            }

            if(p->next != NULL && prev != NULL){
                p->next->Delay += p->Delay; // giữ logic relative delay
            }

            free(p);
            size--;
            return ERROR_SCH_NORMAL;
        }
        prev = p;
        p = p->next;
        idx++;
    }

    Error_code_G = ERROR_SCH_CANNOT_DELETE_TASK;
    return Error_code_G;
}

void SCH_Dispatch_Tasks(void){
    if(head && head->RunMe > 0){
        if(head->pTask){
            head->pTask();
        }
        head->RunMe--;

        uint32_t delay = head->Period;
        void (*pTask)(void) = head->pTask;

        // delete task
        SCH_Delete_Task(0);

        if(delay > 0){
            SCH_Add_Task(pTask, delay, delay);
        }
    }

    SCH_Report_Status();
    SCH_Go_To_Sleep();
}

void SCH_Update(void){
    if(head){
        if(head->Delay > 0){
            head->Delay--;
        } else {
            head->RunMe++;
        }
    }
}

void SCH_Go_To_Sleep(void){
    // Low power mode
}

void SCH_Report_Status(void){
    // Error reporting
}
