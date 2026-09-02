#pragma once

namespace pid
{
    struct Config
    {
        float kp;
        float ki;
        float kd;

        float max_output;
        float max_integral;

        float attenuation_rate;
        float attenuation_breakpoint;
    };

    struct Controller
    {
        explicit Controller(const Config &config);

        float compute(float setpoint, float feedback, float dt, float attenuation_scale = 0.0f);
        void reset();

    private:
        struct State
        {
            float integral{0.0f};
            float feedback{0.0f};
        };
        const Config config;
        State state;
    };
}