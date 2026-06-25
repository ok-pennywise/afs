#include <cstdint>

constexpr std::uintptr_t SPI1_BASE = 0x40013000;

struct SPI
{
    volatile uint32_t CR1;
    volatile uint32_t CR2;
    volatile uint32_t SR;
    volatile uint32_t DR;
};

SPI* const SPI1 = reinterpret_cast<SPI*>(SPI1_BASE);

void init_spi(){
    SPI1->CR1 &= ~(1 << 15); // BIDIMODE = 0
    SPI1->CR1 &= ~(1 << 11); // 8-bit data frame format is selected for transmission/reception
}