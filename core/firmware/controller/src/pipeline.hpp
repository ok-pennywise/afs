#pragma once

#include "priority.hpp"
#include <array>
#include <atomic>
#include <cstdint>

struct Pipeline {
  uint32_t next_run_us;
  uint32_t period_us;

  Priority priority;

  void enable();
  void disable();

  void execute();

  void schedule();
  void clear();

  bool is_enabled();
  bool is_pending();

  bool add_task(void (*callback)());

private:
  static constexpr uint8_t MAX_TASKS = 8;
  uint8_t task_count;

  std::array<void (*)(), MAX_TASKS> tasks;

  std::atomic<bool> enabled{true};
  std::atomic<bool> pending{false};
};
