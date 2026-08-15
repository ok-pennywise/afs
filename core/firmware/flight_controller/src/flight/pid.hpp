#pragma once

namespace pid {

struct Config {
  float kp;
  float ki;
  float kd;

  float max_output;
  float max_integral;
};

struct State {
  float feedback = 0.0f;
  float integral = 0.0f;
};

class Controller {
public:
  explicit Controller(Config config);

  float compute(float setpoint, float feedback, float dt);
  void reset();

private:
  Config config;
  State state;
};
} // namespace pid
