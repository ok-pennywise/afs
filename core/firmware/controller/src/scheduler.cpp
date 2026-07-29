#include "scheduler.hpp"
#include "pipeline.hpp"
#include <cstddef>
#include <cstdint>

bool Scheduler::add_pipeline(Pipeline *pipeline) {
  if (!pipeline) {
    return false;
  }

  if (count >= MAX_PIPELINE_COUNT) {
    return false;
  }

  for (std::size_t i = 0; i < count; i++) {
    if (pipeline == pipelines[i]) {
      return false;
    }
  }

  std::size_t i = count;

  while (i > 0 && pipeline->priority > pipelines[i - 1]->priority) {
    pipelines[i] = pipelines[i - 1];
    --i;
  }

  pipelines[i] = pipeline;
  ++count;
  return true;
}

void Scheduler::run() {
  uint32_t current_us = 0; // placeholder

  for (std::size_t i = 0; i < count; i++) {
    Pipeline *p = pipelines[i];

    if (!p->is_enabled()) {
      continue;
    }

    if (p->is_pending()) {
      p->clear();
    } else if (static_cast<int32_t>(current_us - p->next_run_us) >= 0) {
      p->next_run_us += p->period_us;
    } else {
      continue;
    }

    p->execute();
  }
}

Scheduler &Scheduler::instance() {
  static Scheduler scheduler;
  return scheduler;
}
