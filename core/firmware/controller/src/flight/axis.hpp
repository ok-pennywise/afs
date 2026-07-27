#pragma once
#include "sample.hpp"

enum Axis { X, Y, Z };

struct AxisState {
  Sample gyro;
  Sample acceleration;
  Sample velocity;
  Sample position;
};
