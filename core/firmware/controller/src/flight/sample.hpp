#pragma once

struct Sample {
  void sample(float value);
  void sample(float value, float timestamp);

  void reset();

  float delta() const;
  float value() const;
  float dt() const;

private:
  float t;
  float t_minus_1;

  float timestamp_t;
  float timestamp_t_minus_1;
};
