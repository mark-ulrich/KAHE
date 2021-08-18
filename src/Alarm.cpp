#include <SDL.h>

#include "Alarm.h"

static int
AlarmThread(void* data);

Alarm::Alarm(KTime duration, int loopCount, AlarmCallback callback)
{
  this->duration = duration;
  this->loopCount = loopCount;
  this->callback = callback;

  BeginThread();
}

void
Alarm::BeginThread()
{
  thread = SDL_CreateThread(AlarmThread, "AlarmThread", (void*)this);
}

#include <stdio.h>
int
AlarmThread(void* data)
{
  Alarm* alarm = (Alarm*)data;
  if (!alarm->callback)
    return -1;

  int loopsLeft = alarm->loopCount;
  for (;;)
  {
    while (alarm->clock.Elapsed() < alarm->duration)
      /* Nada */;
    alarm->clock.Reset();

    if (alarm->loopCount > 0 && loopsLeft-- <= 0)
      break;

    alarm->callback();
  }

  return 0;
}