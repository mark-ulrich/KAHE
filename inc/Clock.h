#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "KTime.h"

class Clock
{
  KTime beginTime;
  KTime pauseBeginTime;
  KTime totalPausedTime;

  bool isPaused;

public:
  Clock();

  KTime Reset();
  void Start();
  KTime Pause();

  KTime Elapsed();
};

#endif // __CLOCK_H__
