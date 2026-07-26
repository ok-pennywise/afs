#include "pipeline.hpp"
#include <cstdint>

uint8_t Pipeline::add_task(void (*callback)()) {
  if (task_count >= MAX_TASKS) {
    return 0;
  }
  tasks[++task_count] = callback;
  return 1;
}

void Pipeline::execute() {
  for (uint8_t i = 0; i < task_count; i++) {
      void (*callback)() = tasks[i];
      callback();
  }
}

void Pipeline::enable() { enabled = 1; }
void Pipeline::disable() { enabled = 0; }

void Pipeline::schedule() { pending = 1; };
void Pipeline::clear() { pending = 0; };

uint8_t Pipeline::is_enabled() { return enabled; }
uint8_t Pipeline::is_pending() { return pending; }
