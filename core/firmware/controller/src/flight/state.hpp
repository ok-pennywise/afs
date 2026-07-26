#pragma once

#include "kinematic.hpp"
#include <array>

class State {
private:
  State() = default;
  State(const State &) = delete;
  State &operator=(const State &) = delete;

public:
  std::array<Kinematic, 3> kinematics;

  void init();
  void reset();

  void arm();
  void disarm();

  bool is_armed() const;

  static State *instance() {
    static State state;
    return &state;
  }

private:
  bool armed = false;
};
