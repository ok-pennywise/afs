#include "kinematic.hpp"

void Kinematic::reset() {
  gyro = acceleration = velocity = position = 0.0f;
  gyro_t_minus_1 = acceleration_t_minus_1 = velocity_t_minus_1 =
      position_t_minus_1 = 0.0f;
}

void Kinematic::set(float &current, float &t_minus_1, float &value) {
  t_minus_1 = current;
  current = value;
}

void Kinematic::set_gyro(float g) { set(gyro, gyro_t_minus_1, g); }

void Kinematic::set_acceleration(float a) {
  set(acceleration, acceleration_t_minus_1, a);
}

void Kinematic::set_velocity(float v) { set(velocity, velocity_t_minus_1, v); }

void Kinematic::set_position(float p) { set(position, position_t_minus_1, p); }

float Kinematic::gyro_delta() const { return gyro - gyro_t_minus_1; }

float Kinematic::acceleration_delta() const {
  return acceleration - acceleration_t_minus_1;
}

float Kinematic::velocity_delta() const {
  return velocity - velocity_t_minus_1;
}

float Kinematic::position_delta() const {
  return position - position_t_minus_1;
}
