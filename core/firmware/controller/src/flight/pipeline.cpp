#include "pipeline.hpp"

bool Pipeline::add_task(void (*callback)())
{
    if (task_count >= MAX_TASKS)
        return false;
    tasks[task_count++] = callback;
    return true;
};