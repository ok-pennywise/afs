#pragma once

struct PIDConfig {
  float kp;
  float ki;
  float kd;

  float output_limit;
  float integral_limit;
};

class PID {
  struct PIDState {
    float integral;
    float error;
  };

  PIDState state;

public:
  PIDConfig config;

  explicit PID(const PIDConfig &config);

  float compute(float setpoint, float feedback, float dt);

  void reset();
};
