#include "pid.h"
#include <algorithm>

pid::Controller::Controller(const Config &c) : config(c), state{} {}

float pid::Controller::compute(float setpoint, float feedback, float dt, float attenuation_scale)
{
    if (dt <= 0.0f)
    {
        return 0.0f;
    }

    float error = setpoint - feedback;

    float p_term = config.kp * error;

    state.integral += error * dt;

    state.integral = std::clamp(state.integral, -config.max_integral, config.max_integral);

    float i_term = config.ki * state.integral;

    float d_term = -config.kd * ((feedback - state.feedback) / dt);
    state.feedback = feedback;

    if (attenuation_scale > config.attenuation_breakpoint)
    {
        float m = config.attenuation_rate / config.attenuation_breakpoint;
        float attenuation_factor = 1.0f - (m * (attenuation_scale - config.attenuation_breakpoint));
        
        p_term *= attenuation_factor;
        d_term *= attenuation_factor;
    }

    return std::clamp(p_term + i_term + d_term, -config.max_output, config.max_output);
}

void pid::Controller::reset() { state = {}; }