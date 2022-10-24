#include "FreeRTOSTasks/DummyTask.h"
#include "FreeRTOSTasks/Task.hpp"
#include <iostream>

void DummyTask::execute() {
    for(;;){
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
        HAL_Delay(1000);
        vTaskDelay((pdMS_TO_TICKS(1000)));
    }
}