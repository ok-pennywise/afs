#include "pipeline.hpp"
#include <cstddef>

bool Pipeline::add_task(void (*callback)()) {
  if (count >= MAX_TASK_COUNT) {
    return false;
  }
  tasks[++count] = callback;
  return true;
}

void Pipeline::execute() {
  for (size_t i = 0; i < count; i++) {
    void (*callback)() = tasks[i];
    callback();
  }
}

void Pipeline::set_frequency(float hz) { period_us = 1e6 / hz; }

void Pipeline::schedule() { pending = true; }

void Pipeline::clear() { pending = false; }

void Pipeline::enable() { enabled = true; }

void Pipeline::disable() { enabled = false; }

bool Pipeline::is_enabled() { return enabled; }

bool Pipeline::is_pending() { return pending; }
