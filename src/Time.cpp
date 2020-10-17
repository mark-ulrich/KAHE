#include <SDL.h>

#include "Time.h"
#include "Types.h"

const U64 Time::PerformanceFreq = SDL_GetPerformanceFrequency();

U32
Time::Milliseconds()
{
  return (U32)(Seconds() * 1000.0f);
}

float
Time::Seconds()
{
  return (float)ticks / (float)PerformanceFreq;
}

Time
Time::Now()
{
  Time now;
  return now;
}

Time
Time::operator+(Time& other)
{
  return Time::FromTicks(this->ticks + other.ticks);
}

Time&
Time::operator+=(Time& other)
{
  this->ticks += other.ticks;
  return *this;
}

Time
Time::operator-(Time& other)
{
  return Time::FromTicks(this->ticks - other.ticks);
}

Time&
Time::operator-=(Time& other)
{
  this->ticks -= other.ticks;
  return *this;
}

bool
Time::operator==(Time& other)
{
  return this->ticks == other.ticks;
}

bool
Time::operator>(Time& other)
{
  return this->ticks > other.ticks;
}

bool
Time::operator<(Time& other)
{
  return this->ticks < other.ticks;
}

Time
Time::FromTicks(U64 ticks)
{
  Time time;
  time.ticks = ticks;
  return time;
}

Time
Time::FromSeconds(float seconds)
{
  Time time;
  time.ticks = (U64)(seconds * (float)Time::PerformanceFreq);
  return time;
}