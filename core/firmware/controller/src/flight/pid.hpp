#pragma once

#include "sample.hpp"

struct PIDConfig {
  float kp;
  float ki;
  float kd;

  float output_limit;
  float integral_limit;
};

struct PID {
  PIDConfig config;

  explicit PID(const PIDConfig &config);

  float compute(float setpoint, float feedback, float dt);

  void reset();

private:
  struct PIDState {
    Sample integral = Sample{};
    Sample feedback = Sample{};  
  };

  PIDState state;
};
