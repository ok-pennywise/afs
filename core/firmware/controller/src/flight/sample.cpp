#include "sample.hpp"

void Sample::sample(float value) {
  t_minus_1 = t;
  t = value;
}

void Sample::sample(float value, float timestamp) {
  sample(value);
  timestamp_t_minus_1 = timestamp_t;
  timestamp_t = timestamp;
}

void Sample::reset() { t = t_minus_1 = 0.0f; }

float Sample::delta() const { return t - t_minus_1; }

float Sample::dt() const { return timestamp_t - timestamp_t_minus_1; }

float Sample::value() const { return t; }
