#include "pid.hpp"

void PID::reset() { state.integral = state.error = 0.0f; }

float PID::compute(float setpoint, float feedback, float dt) {
  if (dt <= 0.0f) {
    return 0.0f;
  }

  float error = setpoint - feedback;

  float p_term = config.kp * error;

  state.integral += error * dt;

  if (state.integral > config.integral_limit) {
    state.integral = config.integral_limit;
  }

  if (state.integral < -config.integral_limit) {
    state.integral = -config.integral_limit;
  }

  float i_term = config.ki * state.integral;

  float d_term = config.kd * (error - state.error) / dt;

  state.error = error;
  
  float output = p_term + i_term + d_term;

  if (output > config.output_limit) {
    output = config.output_limit;
  }

  if (output < -config.output_limit) {
    output = -config.output_limit;
  }

  return output;
}
