#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

struct Task
{
    void (*callback)();
};

struct Pipeline
{
    static constexpr std::size_t MAX_TASKS = 8;

    std::array<Task *, MAX_TASKS> tasks;

    std::size_t task_count = 0;

    uint64_t period_us = 0;
    uint64_t last_run_us = 0;

    uint32_t pending = 0;

    bool add_task(Task* task);
};

class Scheduler
{
public:
    static constexpr std::size_t MAX_PIPELINES = 16;

    bool add_pipeline(Pipeline *pipeline);

    void trigger(Pipeline *pipeline);

    void run(uint64_t now_us);

private:
    std::array<Pipeline *, MAX_PIPELINES> pipelines{};
    std::size_t pipeline_count = 0;
};