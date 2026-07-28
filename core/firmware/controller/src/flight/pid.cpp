#include "pid.hpp"

#include <algorithm>

void PID::reset() { state = PIDState{}; }

float PID::compute(float setpoint, float feedback, float dt) {
  if (dt <= 0.0f) {
    return 0.0f;
  }

  float error = setpoint - feedback;

  float p_term = config.kp * error;

  state.integral.accumulate(error * dt);
  state.integral.clamp(-config.integral_limit, config.integral_limit);
  float i_term = config.ki * state.integral.value();
  
  state.feedback.sample(feedback);
  float d_term = -config.kd * state.feedback.delta() / dt;

  float output = p_term + i_term + d_term;

  return std::clamp(output, -config.output_limit, config.output_limit);
}
