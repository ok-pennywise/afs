#include "pipeline.hpp"
#include <cstdint>

bool Pipeline::add_task(void (*callback)()) {
  if (task_count >= MAX_TASKS) {
    return false;
  }
  tasks[++task_count] = callback;
  return true;
}

void Pipeline::execute() {
  for (uint8_t i = 0; i < task_count; i++) {
    void (*callback)() = tasks[i];
    callback();
  }
}

void Pipeline::enable() { enabled = true; }
void Pipeline::disable() { enabled = false; }

void Pipeline::schedule() { pending = 1; };
void Pipeline::clear() { pending = 0; };

bool Pipeline::is_enabled() { return enabled; }
bool Pipeline::is_pending() { return pending; }
