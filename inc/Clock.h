#ifndef __CLOCK_H__
#define __CLOCK_H__

#include "Time.h"

class Clock
{
  Time beginTime;
  Time pauseBeginTime;
  Time totalPausedTime;

  bool isPaused;

public:
  Clock();

  Time Reset();
  void Start();
  Time Pause();

  Time Elapsed();
};

#endif // __CLOCK_H__
