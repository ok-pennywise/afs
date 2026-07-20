#include "axis.hpp"

int16_t Axis::rate_delta() const { return measured_rate - previous_rate; }

int16_t Axis::acceleration_delta() const { return measured_acceleration - previous_acceleration; }

int16_t Axis::rate_error() const { return rate_setpoint - measured_rate; }

int16_t Axis::acceleration_error() const { return acceleration_setpoint - measured_acceleration; }

void Axis::update_rate_measurement(int16_t value)
{
    previous_rate = measured_rate;
    measured_rate = value;
}

void Axis::update_acceleration_measurement(int16_t value)
{
    previous_acceleration = measured_acceleration;
    measured_acceleration = value;
}

void Axis::set_rate_setpoint(int16_t value) { rate_setpoint = value; }

void Axis::set_acceleration_setpoint(int16_t value) { acceleration_setpoint = value; }