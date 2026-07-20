#include "pipeline.hpp"

uint8_t Pipeline::add_task(void (*callback)())
{
    if (task_count >= MAX_TASKS)
        return 0;
    tasks[task_count++] = callback;
    return 1;
};
