#include "pipeline.hpp"
#include <array>
#include <cstdint>

class Scheduler {
private:
  Scheduler() = default;
  Scheduler(const Scheduler &) = delete;
  Scheduler &operator=(const Scheduler &) = delete;

  static constexpr uint8_t MAX_PIPELINES = 32;
  std::array<Pipeline *, MAX_PIPELINES> pipelines;
  uint8_t pipeline_count = 0;

public:
  uint8_t add_pipeline(Pipeline *p);
  void run();

  static Scheduler *instance() {
    static Scheduler scheduler;
    return &scheduler;
  }
};
