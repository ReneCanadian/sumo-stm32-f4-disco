#include <tim.h>
#include "include/customMain.hpp"
#include "main.h"

extern "C" void custom_main() {
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_2);
    int32_t PWM_1 = 75;
    int32_t PWM_2 = 75;
    while (1){
        HAL_GPIO_WritePin(BI1_GPIO_Port, BI1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(BI2_GPIO_Port, BI2_Pin, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(AI1_GPIO_Port, AI1_Pin, GPIO_PIN_SET);
        HAL_GPIO_WritePin(AI2_GPIO_Port, AI2_Pin, GPIO_PIN_RESET);
        TIM3->CCR1 = PWM_1;
        TIM3->CCR2 = PWM_2;
    }
}
