#pragma once

struct CommandConfig {
  float scale;
  bool invert = false;
  float deadband;

  float min = 0.0f;
  float max = 1000.0f;
};

struct Command {
  CommandConfig config;
  float input;
  float setpoint() const;
};
