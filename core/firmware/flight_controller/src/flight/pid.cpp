#include "pid.hpp"
#include <algorithm>

float pid::Controller::compute(float setpoint, float feedback, float dt) {
  if (dt <= 0.0f) {
    return 0.0f;
  }

  float error = setpoint - feedback;
  float p = config.kp * error;

  state.integral += error * dt;
  state.integral =
      std::clamp(state.integral, -config.max_integral, config.max_integral);
  float i = config.ki * state.integral;

  float d = -config.kd * (feedback - state.feedback) / dt;
  state.feedback = feedback;

  return std::clamp(p + i + d, -config.max_output, config.max_output);
}

void pid::Controller::reset() { state = State{}; }
