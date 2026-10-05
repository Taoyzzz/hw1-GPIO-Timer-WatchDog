#include "tasks.h"
#include "main.h"
#include "tim.h"    
#include "iwdg.h" 

volatile uint32_t tick = 0;
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick++; 
        
        //HAL_IWDG_Refresh(&hiwdg); 
    }
}
void Tasks_Init(void)
{
    HAL_TIM_Base_Start_IT(&htim2); 
    
    HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);
}