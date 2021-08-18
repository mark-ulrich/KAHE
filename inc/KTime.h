#ifndef __KTIME_H__
#define __KTIME_H__

#include <SDL.h>

#include "Types.h"

class KTime
{
  static const U64 PerformanceFreq;

  U64 ticks;

public:
  KTime()
    : KTime(SDL_GetPerformanceCounter())
  {}

  KTime(U64 ticks)
    : ticks(ticks)
  {}

  U32 Milliseconds();

  float Seconds();

  static KTime Now();

  /*
    Operators
  */

  KTime operator+(KTime& other);
  KTime& operator+=(KTime& other);
  KTime operator-(KTime& other);
  KTime& operator-=(KTime& other);
  bool operator==(KTime& other);
  bool operator<(KTime& other);
  bool operator>(KTime& other);

  /*
    Factory Methods
  */

  static KTime FromTicks(U64 ticks);
  static KTime FromMilliseconds(U32 milliseconds);
  static KTime FromSeconds(float seconds);

  // TODO: Remove after debugging
  friend class Clock;
};

#endif // __TIME_H__
