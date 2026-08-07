#include "pid.hpp"

void PID::Controller::compute(float error, float feedback, float dt){
  float p_term = config.KP * error;
}
