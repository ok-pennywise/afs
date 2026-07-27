#include "scheduler.hpp"
#include "pipeline.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdint>

bool Scheduler::add_pipeline(Pipeline *pipeline) {
  if (count >= MAX_PIPELINE_COUNT) {
    return false;
  }

  pipelines[count++] = pipeline;
  std::sort(pipelines.begin(), pipelines.begin() + count,
            [](const Pipeline *a, const Pipeline *b) {
              return a->priority < b->priority;
            });

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
    } else if (current_us - p->next_run_us >= 0) {
      p->next_run_us += p->period_us;
    } else {
      continue;
    }

    p->execute();
  }
}
