#include <SDL.h>

#include "KTime.h"
#include "Types.h"

const U64 KTime::PerformanceFreq = SDL_GetPerformanceFrequency();

U32
KTime::Milliseconds()
{
  return (U32)(Seconds() * 1000.0f);
}

float
KTime::Seconds()
{
  return (float)ticks / (float)PerformanceFreq;
}

KTime
KTime::Now()
{
  KTime now;
  return now;
}

KTime
KTime::operator+(KTime& other)
{
  return KTime::FromTicks(this->ticks + other.ticks);
}

KTime&
KTime::operator+=(KTime& other)
{
  this->ticks += other.ticks;
  return *this;
}

KTime
KTime::operator-(KTime& other)
{
  return KTime::FromTicks(this->ticks - other.ticks);
}

KTime&
KTime::operator-=(KTime& other)
{
  this->ticks -= other.ticks;
  return *this;
}

bool
KTime::operator==(KTime& other)
{
  return this->ticks == other.ticks;
}

bool
KTime::operator>(KTime& other)
{
  return this->ticks > other.ticks;
}

bool
KTime::operator<(KTime& other)
{
  return this->ticks < other.ticks;
}

KTime
KTime::FromTicks(U64 ticks)
{
  KTime time;
  time.ticks = ticks;
  return time;
}

KTime
KTime::FromSeconds(float seconds)
{
  KTime time;
  time.ticks = (U64)(seconds * (float)KTime::PerformanceFreq);
  return time;
}