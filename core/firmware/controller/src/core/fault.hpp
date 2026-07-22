#include "priority.hpp"

enum class FaultType
{
    IMU_NOT_RESPONDING,
    BARO_NOT_RESPONDING,
    FLASH_NOT_RESPONDING,

    GPS_SIGNAL_LOST,
    RADIO_SIGNAL_LOST,

    BATTERY_LOW
};

struct Fault
{
    FaultType type;
    Priority priority;
    
};