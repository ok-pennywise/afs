#pragma once
#include <cstdint>
#include <array>

namespace radio
{
    constexpr size_t max_channels = 24;
    
    struct ChannelConfig
    {
        uint16_t min;
        uint16_t max;
        uint16_t deadband;

        bool processed;
        bool inverted;
    };

    struct Channel
    {
        uint16_t current;
        uint16_t previous;

        ChannelConfig config;

        int16_t delta() const;
    };

    struct Control
    {
        Channel read(uint8_t index);
        void update();

    private:
        std::array<Channel, max_channels> buffer;
    };
}
