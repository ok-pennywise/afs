#include "pipeline.hpp"
#include <cstddef>
#include <cstdint>

bool Pipeline::add_task(void (*callback)()) {
  if (count >= MAX_TASK_COUNT) {
    return false;
  }
  tasks[count++] = callback;
  return true;
}

void Pipeline::execute() {
  for (size_t i = 0; i < count; i++) {
    tasks[i]();
  }
}

void Pipeline::set_frequency(float hz) {
  period_us = static_cast<uint32_t>(1000000.0f / hz);
}

void Pipeline::schedule() { pending = true; }

void Pipeline::clear() { pending = false; }

void Pipeline::enable() { enabled = true; }

void Pipeline::disable() { enabled = false; }

bool Pipeline::is_enabled() { return enabled; }

bool Pipeline::is_pending() { return pending; }
