#pragma once

#include "pipeline.hpp"
#include <array>
#include <cstddef>

struct Scheduler {
  bool add_pipeline(Pipeline *pipeline);
  void run();

private:
  static constexpr std::size_t MAX_PIPELINE_COUNT = 255;
  
  std::array<Pipeline *, 255> pipelines;
  std::size_t count = 0;
};
