#pragma once

#include <cstdint>

struct Sample {
  void sample(float v);
  void sample(float v, uint32_t timestamp);

  void accumulate(float v);
  void accumulate(float v, uint32_t timestamp);

  void reset();

  float value();
  float delta();
  uint32_t dt();
  
  
private:
  float t;
  float t_minus_1;

  uint32_t timestamp_t;
  uint32_t timestamp_t_minus_1;
};
