/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdlib.h>
#include "stdio.h"
#include "i2c_lcd.h"
#include "scheduler.h"
#include "fsm_auto_mode.h"
#include "fsm_control_mode.h"
#include "fsm_reset_mode.h"
#include "fsm_config_mode.h"
#include "fsm_manual_mode.h"
#include "LED_display.h"
#include "LCD_display.h"
#include <string.h>
#include "input_reading.h"
#include "input_processing.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON_4_Pin GPIO_PIN_10
#define BUTTON_4_GPIO_Port GPIOB
#define B2_Pin GPIO_PIN_7
#define B2_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_8
#define B1_GPIO_Port GPIOA
#define A1_Pin GPIO_PIN_9
#define A1_GPIO_Port GPIOA
#define BUTTON_1_Pin GPIO_PIN_3
#define BUTTON_1_GPIO_Port GPIOB
#define BUTTON_3_Pin GPIO_PIN_4
#define BUTTON_3_GPIO_Port GPIOB
#define BUTTON_2_Pin GPIO_PIN_5
#define BUTTON_2_GPIO_Port GPIOB
#define A2_Pin GPIO_PIN_6
#define A2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
