#include "Clock.h"
#include "Util.h"

Clock::Clock()
{
  totalPausedTime = KTime::FromTicks(0);
  pauseBeginTime = KTime::FromTicks(0);
  isPaused = true;

  Reset();
}

KTime
Clock::Reset()
{
  KTime elapsedTime = Elapsed();
  beginTime = KTime::Now();
  // Prevent overflow bug
  if (isPaused)
    pauseBeginTime = beginTime;
  totalPausedTime = KTime::FromTicks(0);
  return elapsedTime;
}

void
Clock::Start()
{
  if (!isPaused)
    return;

  totalPausedTime += KTime::Now() - pauseBeginTime;
  pauseBeginTime = KTime::FromTicks(0);
  isPaused = false;
}

KTime
Clock::Pause()
{
  if (isPaused)
    return Elapsed();

  isPaused = true;
  pauseBeginTime = KTime::Now();
  return Elapsed();
}

const float MaxPauseSeconds = 60.0f * 60.0f * 24.0f * 365.0f;
KTime
Clock::Elapsed()
{
  // printf("\nBeginTime: %f\n", beginTime.Seconds());
  // printf("PauseBeginTime: %f\n", pauseBeginTime.Seconds());
  // printf("TotalPausedTime: %f\n", totalPausedTime.Seconds());
  if (isPaused)
  {
    totalPausedTime += KTime::Now();
    totalPausedTime -= pauseBeginTime;
  }
  // printf("TotalPausedTime: %f\n", totalPausedTime.Seconds());
  KTime elapsedTime = KTime::Now();
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  elapsedTime -= beginTime;
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  elapsedTime -= totalPausedTime;
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  // HACK: Fixes overflow bug
  if (elapsedTime.ticks & 0x8000000000000000)
    elapsedTime = KTime::FromTicks(0);
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());

  return elapsedTime;
}