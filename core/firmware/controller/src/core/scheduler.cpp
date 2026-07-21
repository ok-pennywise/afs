#include "scheduler.hpp"

uint8_t Scheduler::add_pipeline(Pipeline *p)
{
    if (pipeline_count >= MAX_PIPELINES)
        return 0;

    uint8_t i = pipeline_count;

    while (i > 0 && (pipelines[i - 1]->priority) > (p->priority))
    {
        pipelines[i] = pipelines[i - 1];
        --i;
    }

    pipelines[i] = p;
    ++pipeline_count;

    return 1;
}

void Scheduler::run()
{
    uint32_t current_time_us = 0;
    for (uint8_t i = 0; i < pipeline_count; ++i)
    {
        Pipeline *p = pipelines[i];

        if (p->pending != 0)
        {
            p->pending = 0;
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
        p->execute();
    }
}

void Scheduler::dispatch(Pipeline *p)
{
    p->pending = 1;
}
