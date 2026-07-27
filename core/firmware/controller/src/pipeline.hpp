#pragma once

#include "priority.hpp"
#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>

struct Pipeline {
  bool add_task(void (*callback)());
  void execute();

  void enable();
  void disable();

  void schedule();
  void clear();

  bool is_enabled();
  bool is_pending();

  void set_frequency(float hz);

  uint32_t next_run_us;
  uint32_t period_us;

  Priority priority;

private:
  static constexpr std::size_t MAX_TASK_COUNT = 255;

  std::array<void (*)(), MAX_TASK_COUNT> tasks;
  std::size_t count = 0;

  std::atomic<bool> pending{false};
  std::atomic<bool> enabled{true};
};
