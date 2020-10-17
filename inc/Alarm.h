/**
 * Alarm
 * -----
 *  A simple callback timer
 **/

#ifndef __ALARM_H__
#define __ALARM_H__

#include "Clock.h"
#include "Time.h"

typedef void (*AlarmCallback)(void);

class Alarm
{

  Clock clock;
  int loopCount;
  Time duration;
  AlarmCallback callback;
  SDL_Thread* thread;

private:
  void BeginThread();

  friend static int AlarmThread(void* data);

public:
  Alarm(Time duration, AlarmCallback callback)
    : Alarm(duration, 0, callback)
  {}

  Alarm(Time duration, int loopCount, AlarmCallback callback);

  // ~Alarm() { printf("ALARM DEAD"); }

  void Reset();
  void Pause();
  void Start();
};

#endif // __ALARM_H__
