#include "radio.h"
#include <algorithm>
#include <cmath>

int16_t radio::Channel::delta() const
{
    return (int16_t)(current) - (int16_t)(previous);
}

radio::Channel radio::Control::read(uint8_t index)
{
    if (index >= max_channels)
    {
        return Channel{};
    }

    Channel channel = buffer[index];

    if (channel.config.processed)
    {
        return channel;
    }

    if (channel.config.inverted)
    {
        channel.current = (channel.config.max + channel.config.min) - channel.current;
    }

    channel.current = std::clamp(channel.current, channel.config.min, channel.config.max);

    if (std::abs(channel.delta()) <= channel.config.deadband)
    {
        channel.current = channel.previous;
    }
    else
    {
        channel.previous = channel.current;
        buffer[index] = channel;
    }

    return channel;
}