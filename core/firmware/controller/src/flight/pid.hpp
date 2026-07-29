#pragma once

#include "sample.hpp"

struct PIDConfig {
  float KP;
  float KI;
  float KD;

  float output_max;
  float integral_max;
};

struct PID {
  PIDConfig config;

  explicit PID(PIDConfig config);

  float compute(float setpoint, float feedback, float dt);
  void reset();

private:
  struct State {
    Sample integral = Sample{};
    Sample feedback = Sample{};
  };

  State state;
};
