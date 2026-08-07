#pragma once

namespace PID {
struct Config {
  float KP;
  float KI;
  float KD;

  float max_output;
  float max_integral;
};

struct State {
  float feedback = 0.0f;
  float integral = 0.0f;
};

struct Controller {
  explicit Controller(const Config *config);
  void compute(float error, float feedback, float dt);
  void reset();
  State state;
};
} // namespace PID
