#pragma once

#include <array>
#include <cstdint>

#include "pipeline.hpp"

class Scheduler
{

    static constexpr uint8_t MAX_PIPELINES = 16;

    std::array<Pipeline *, MAX_PIPELINES> pipelines;
    uint8_t pipeline_count = 0;

public:
    uint8_t add_pipeline(Pipeline *p);
    void run();
    void dispatch(Pipeline *p);
};
