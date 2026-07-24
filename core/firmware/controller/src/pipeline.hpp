#include <cstdint>
#include <array>
#include <atomic>

class Pipeline{
    static constexpr uint8_t MAX_TASKS = 8;
    uint8_t task_count;

    std::array<void (*)(), MAX_TASKS> tasks;
    std::atomic<uint8_t> enabled;
    std::atomic<uint8_t> pending;
};