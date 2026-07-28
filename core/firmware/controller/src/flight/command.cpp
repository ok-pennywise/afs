#include "command.hpp"
#include <algorithm>
#include <cstdlib>

float Command::setpoint() const {
  float x = input;

  x = std::clamp(x, config.min, config.max);

  float neutral = 0.5f * (config.min + config.max);
  x -= neutral;

  if (std::abs(x) < config.deadband) {
    x = 0.0f;
  }

  if (config.invert) {
    x = -x;
  }
  return x * config.scale;
}
