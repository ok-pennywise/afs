#include "flight/pid.hpp"

int main() {

  PID{PIDConfig{
      .KP = 1.0f,
      .KI = 0.08f,
      .KD = 1.01f,
      .output_max = 400,
      .integral_max = 400,
  }};
}
