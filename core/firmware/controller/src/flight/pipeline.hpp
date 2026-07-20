#pragma once

#include <array>
#include <atomic>
#include <cstdint>

enum PipelinePriority : uint8_t
{
    CRITICAL,
    HIGH,
    NORMAL,
    LOW
};

struct Pipeline
{
    PipelinePriority priority;

    uint8_t add_task(void (*callback)());

    std::atomic<uint8_t> pending{0};

    uint32_t next_run_us = 0;
    uint32_t period_us = 0;

    static constexpr uint8_t MAX_TASKS = 8;

    std::array<void (*)(), MAX_TASKS> tasks;
    uint8_t task_count = 0;
};
