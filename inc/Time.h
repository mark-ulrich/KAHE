#ifndef __TIME_H__
#define __TIME_H__

#include <SDL.h>

#include "Types.h"

class Time
{
  static const U64 PerformanceFreq;

  U64 ticks;

public:
  Time()
    : Time(SDL_GetPerformanceCounter())
  {}

  Time(U64 ticks)
    : ticks(ticks)
  {}

  U32 Milliseconds();

  float Seconds();

  static Time Now();

  /*
    Operators
  */

  Time operator+(Time& other);
  Time& operator+=(Time& other);
  Time operator-(Time& other);
  Time& operator-=(Time& other);
  bool operator==(Time& other);
  bool operator<(Time& other);
  bool operator>(Time& other);

  /*
    Factory Methods
  */

  static Time FromTicks(U64 ticks);
  static Time FromMilliseconds(U32 milliseconds);
  static Time FromSeconds(float seconds);

  // TODO: Remove after debugging
  friend class Clock;
};

#endif // __TIME_H__
