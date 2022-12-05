#pragma once

#include "Task.hpp"
#include "queue.h"
#include <etl/optional.h>

class DummyPacketMakerTask : public Task{
private:
    static constexpr uint16_t TaskStackDepth = 2000;

    StackType_t taskStack[TaskStackDepth];
public:
    void execute();

    DummyPacketMakerTask() : Task("PacketMaker"){}

    void createTask(){
        xTaskCreateStatic(vClassTask<DummyPacketMakerTask>, this->TaskName,
                          DummyPacketMakerTask::TaskStackDepth, this, tskIDLE_PRIORITY +1,
                          this->taskStack, &(this->taskBuffer));
    }
};
inline etl::optional<DummyPacketMakerTask> dummyPacketMakerTask;
extern QueueHandle_t transmitPacketsQueue;
extern QueueHandle_t transmitPacketLengthsQueue;
