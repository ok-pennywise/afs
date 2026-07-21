#include <cstdint>
#include "pipeline.hpp"

uint8_t Pipeline::add_task(void (*callback)())
{
    if (task_count >= MAX_TASKS)
    {
        return 0;
    }
    tasks[task_count++] = callback;
    return 1;
}

void Pipeline::execute()
{
    for (uint8_t i = 0; i < task_count; i++)
    {
        void (*callback)() = tasks[i];
        callback();
    }
}