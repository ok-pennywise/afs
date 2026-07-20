#include "scheduler.hpp"

bool Scheduler::add_pipeline(Pipeline *p)
{
    if (pipeline_count >= MAX_PIPELINES)
        return false;

    uint8_t position = pipeline_count;

    while (position > 0 &&
           (pipelines[position - 1]->priority) >
               (p->priority))
    {
        pipelines[position] = pipelines[position - 1];
        --position;
    }

    pipelines[position] = p;
    ++pipeline_count;

    return true;
}

void Scheduler::run()
{
    uint32_t current_time_us = 0;
    for (uint8_t i = 0; i < pipeline_count; ++i)
    {
        Pipeline *p = pipelines[i];

        if (p->pending > 0)
        {
            --p->pending;
        }
        else if (p->period_us != 0)
        {
            if ((int32_t)(current_time_us - p->next_run_us) < 0)
                continue;

            p->next_run_us += p->period_us;
        }
        else
        {
            continue;
        }

        for (uint8_t j = 0; j < p->task_count; ++j)
        {
            void (*callback)() = p->tasks[j];
            callback();
        }
    }
}

void Scheduler::dispatch(Pipeline *p) { p->pending++; }