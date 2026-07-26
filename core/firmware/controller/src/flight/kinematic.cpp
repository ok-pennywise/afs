#include "kinematic.hpp"

void Kinematic::reset() {
  gyro = acceleration = velocity = position = 0.0f;
  gyro_t_minus_1 = acceleration_t_minus_1 = velocity_t_minus_1 =
      position_t_minus_1 = 0.0f;
}

void Kinematic::set_gyro(float g) {
  gyro_t_minus_1 = gyro;
  gyro = g;
}

void Kinematic::set_acceleration(float a) {
  acceleration_t_minus_1 = acceleration;
  acceleration = a;
}

void Kinematic::set_velocity(float v) {
  velocity_t_minus_1 = velocity;
  velocity = v;
}

void Kinematic::set_position(float p) {
  position_t_minus_1 = position;
  position = p;
}

float Kinematic::gyro_delta() const { return gyro - gyro_t_minus_1; }

float Kinematic::acceleration_delta() const {
  return acceleration - acceleration_t_minus_1;
}

float Kinematic::velocity_delta() const { return velocity - velocity_t_minus_1; }

float Kinematic::position_delta() const { return position - position_t_minus_1; }
