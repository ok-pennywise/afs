#include "cstdint"

void time_init();
void delay_us(uint64_t t);
void delay_ms(uint64_t t);

uint64_t time_us();
uint64_t time_ms();
