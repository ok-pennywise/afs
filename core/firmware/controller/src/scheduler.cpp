#include "scheduler.hpp"
#include "pipeline.hpp"
#include <cstdint>

uint8_t Scheduler::add_pipeline(Pipeline *p) {
  if (pipeline_count >= MAX_PIPELINES) {
    return 0;
  }
  uint8_t i = pipeline_count;
  while (i > 0 && pipelines[i - 1]->priority > p->priority) {
    pipelines[i] = pipelines[i - 1];
    --i;
  }
  pipelines[i] = p;
  ++pipeline_count;
  return 1;
};

void Scheduler::run() {
  uint32_t current_us = 0; // Placeholder

  for (uint8_t i = 0; i < pipeline_count; ++i) {
    Pipeline *p = pipelines[i];

    if (!p->is_enabled()) {
      continue;
    }

    if (p->is_pending()) {
      p->clear();
    } else if (static_cast<int32_t>(current_us - p->next_run_us) < 0) {
      continue;
    }

    if (p->period_us != 0) {
      p->next_run_us += p->period_us;
    }

    p->execute();
  }
}
