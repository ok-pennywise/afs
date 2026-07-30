#include "pid.hpp"
#include <algorithm>
#include <cstdint>

void PID::reset() { state = State{}; }

PID::PID(PIDConfig config) { config = config; }

float PID::compute(float setpoint, float feedback, uint32_t dt) {
  if (dt < 0) {
    return 0.0f;
  }

  float error = setpoint - feedback;

  float p_term = config.KP * error;

  state.integral.accumulate(error * dt);
  state.integral.sample(std::clamp(state.integral.value(), -config.integral_max,
                                   config.integral_max));
  float i_term = config.KI * state.integral.value();

  state.feedback.sample(feedback);
  float d_term = -config.KD * (state.feedback.delta()) * dt;

  float output = p_term + i_term + d_term;

  return std::clamp(output, -config.output_max, config.output_max);
}
