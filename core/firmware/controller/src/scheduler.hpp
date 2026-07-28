#pragma once

#include "pipeline.hpp"
#include <array>
#include <cstddef>

struct Scheduler {
  bool add_pipeline(Pipeline *pipeline);
  void run();

  static Scheduler *instance();

private:
  Scheduler() = default;
  static constexpr std::size_t MAX_PIPELINE_COUNT = 255;

  std::array<Pipeline *, MAX_PIPELINE_COUNT> pipelines;
  std::size_t count = 0;
};
