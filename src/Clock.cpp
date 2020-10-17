#include "Clock.h"
#include "Util.h"

Clock::Clock()
{
  totalPausedTime = Time::FromTicks(0);
  pauseBeginTime = Time::FromTicks(0);
  isPaused = true;

  Reset();
}

Time
Clock::Reset()
{
  Time elapsedTime = Elapsed();
  beginTime = Time::Now();
  // Prevent overflow bug
  if (isPaused)
    pauseBeginTime = beginTime;
  totalPausedTime = Time::FromTicks(0);
  return elapsedTime;
}

void
Clock::Start()
{
  if (!isPaused)
    return;

  totalPausedTime += Time::Now() - pauseBeginTime;
  pauseBeginTime = Time::FromTicks(0);
  isPaused = false;
}

Time
Clock::Pause()
{
  if (isPaused)
    return Elapsed();

  isPaused = true;
  pauseBeginTime = Time::Now();
  return Elapsed();
}

const float MaxPauseSeconds = 60.0f * 60.0f * 24.0f * 365.0f;
Time
Clock::Elapsed()
{
  // printf("\nBeginTime: %f\n", beginTime.Seconds());
  // printf("PauseBeginTime: %f\n", pauseBeginTime.Seconds());
  // printf("TotalPausedTime: %f\n", totalPausedTime.Seconds());
  if (isPaused)
  {
    totalPausedTime += Time::Now();
    totalPausedTime -= pauseBeginTime;
  }
  // printf("TotalPausedTime: %f\n", totalPausedTime.Seconds());
  Time elapsedTime = Time::Now();
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  elapsedTime -= beginTime;
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  elapsedTime -= totalPausedTime;
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());
  // HACK: Fixes overflow bug
  if (elapsedTime.ticks & 0x8000000000000000)
    elapsedTime = Time::FromTicks(0);
  // printf("ElapsedTime: %f\n", elapsedTime.Seconds());

  return elapsedTime;
}