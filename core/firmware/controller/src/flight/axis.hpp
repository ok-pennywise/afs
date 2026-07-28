#pragma once

#include "sample.hpp"
#include <cstddef>

enum Axis { X, Y, Z };

constexpr std::size_t AXIS_COUNT = 3;

struct AxisState {
  Sample gyro;
  Sample acceleration;
  Sample velocity;
  Sample position;
};
