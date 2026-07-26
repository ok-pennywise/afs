#include "state.hpp"
#include "axis.hpp"

void State::init() {
  for (int axis = Axis::X; axis <= Axis::Z; ++axis) {
      kinematics[axis] = Kinematic();
  }
}

void State::reset() {
  for (auto &k : kinematics) {
    k.reset();
  }
}
