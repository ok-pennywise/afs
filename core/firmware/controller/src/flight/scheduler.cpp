#include "scheduler.hpp"

bool Pipeline::add_task(Task *task)
{
    if (task_count >= MAX_TASKS)
        return false;

    tasks[task_count++] = task;
    return true;
}

bool Scheduler::add_pipeline(Pipeline *pipeline)
{
    if (pipeline_count >= MAX_PIPELINES)
        return false;

    pipelines[pipeline_count++] = pipeline;
    return true;
}

void Scheduler::trigger(Pipeline *pipeline)
{
    ++pipeline->pending;
}

void Scheduler::run(uint64_t now_us)
{
    for (std::size_t i = 0; i < pipeline_count; ++i)
    {
        Pipeline *pipeline = pipelines[i];

        while (pipeline->pending > 0)
        {
            --pipeline->pending;

            for (std::size_t j = 0; j < pipeline->task_count; ++j)
            {
                pipeline->tasks[j]->callback();
            }
        }

        if (pipeline->period_us == 0)
            continue;

        if ((now_us - pipeline->last_run_us) >= pipeline->period_us)
        {
            pipeline->last_run_us = now_us;

            for (std::size_t j = 0; j < pipeline->task_count; ++j)
            {
                pipeline->tasks[j]->callback();
            }
        }
    }
}