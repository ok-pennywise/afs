#pragma once

#include <cstdint>
#include <atomic>
#include <array>
#include "priority.hpp"

struct Pipeline
{
    Priority priority;

    uint8_t add_task(void (*callback)());

    std::atomic<uint8_t> pending{0};

    uint32_t next_run_us = 0;
    uint32_t period_us = 0;

    void execute();
    void disable();
    void enable();
    bool is_enabled();

private:
    static constexpr uint8_t MAX_TASKS = 8;

    std::array<void (*)(), MAX_TASKS> tasks;
    uint8_t task_count = 0;
    std::atomic<uint8_t> enabled{1};
};