#include "kinematic.hpp"
#include <array>

struct State{
    std::array<Kinematic, 3> kinematics;

    void init();
    void reset();
};