#pragma once

struct Sample {
  Sample();
  
  void sample(float value);
  void sample(float value, float timestamp);

  void accumulate(float value);
  void accumulate(float value, float timestamp);

  void clamp(float min, float max);

  void reset();

  float delta() const;
  float dt() const;
  float value() const;

private:
  float t = 0.0f;
  float t_minus_1 = 0.0f;

  float timestamp_t = 0.0f;
  float timestamp_t_minus_1 = 0.0f;
};