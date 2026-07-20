#pragma once

#include <cstdint>

struct Axis
{
    int16_t rate_setpoint;
    int16_t acceleration_setpoint;

    int16_t measured_rate;
    int16_t measured_acceleration;

    int16_t previous_rate;
    int16_t previous_acceleration;

    int16_t rate_delta() const;
    int16_t acceleration_delta() const;

    int16_t rate_error() const;
    int16_t acceleration_error() const;

    void update_rate_measurement(int16_t value);
    void update_acceleration_measurement(int16_t value);

    void set_rate_setpoint(int16_t value);
    void set_acceleration_setpoint(int16_t value);
};