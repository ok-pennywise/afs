#pragma once

struct Kinematic {
  float gyro;
  float gyro_t_minus_1;

  float acceleration;
  float acceleration_t_minus_1;

  float velocity;
  float velocity_t_minus_1;

  float position;
  float position_t_minus_1;

  void reset();

  void set_gyro(float g);
  void set_acceleration(float a);
  void set_velocity(float v);
  void set_position(float p);

  float gyro_delta() const;
  float acceleration_delta() const;
  float velocity_delta() const;
  float position_delta() const;

  private:
      void set(float& current, float& t_minus_1, float& value);
};
