#include "sample.hpp"
#include <cstdint>

void Sample::sample(float v) {
  t_minus_1 = t;
  t = v;
}

void Sample::sample(float v, uint32_t timestamp) {
  sample(v);
  timestamp_t_minus_1 = timestamp_t;
  timestamp_t = timestamp;
}

void Sample::reset() {
  t = t_minus_1 = 0.0f;
  timestamp_t = timestamp_t_minus_1 = 0;
}

void Sample::accumulate(float v) { sample(t + v); }

void Sample::accumulate(float v, uint32_t timestamp) {
  sample(t + v, timestamp);
}

float Sample::value() { return t; }

float Sample::delta() { return t - t_minus_1; }

uint32_t Sample::dt() { return timestamp_t - timestamp_t_minus_1; }
