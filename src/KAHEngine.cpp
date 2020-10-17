#include <SDL.h>
#include <string.h>

#include "Alarm.h"
#include "Clock.h"
#include "KAHEngine.h"
#include "Util.h"

KAHEngine::KAHEngine()
{
  dataDirectory = KString::Format("%s/data", SDL_GetBasePath());

  display = nullptr;
  uiManager = nullptr;
}

KAHEngine::~KAHEngine()
{
  SAFE_DELETE(display);
  SDL_Quit();
}

#include <stdio.h>
void
TestFunc()
{
  static U32 callCount = 0;
  // printf("TestFunc [%d]\n", ++callCount);
}

void
KAHEngine::Run()
{
  Clock clock;

  // Alarm alarm(Time::FromSeconds(1.0f), 10, TestFunc);

  isRunning = true;
  while (isRunning)
  {
    SDL_Event ev;
    if (SDL_PollEvent(&ev))
    {
      if (ev.type == SDL_QUIT)
      {
        isRunning = false;
        break;
      }
    }

    uiManager->Render();
    display->Render();

    // printf("Time: %.2fs\n", clock.Elapsed().Seconds());
  }
}

void
KAHEngine::SetDataDirectory(KString const& path)
{
  dataDirectory = path;
}

void
KAHEngine::InitializeDisplay()
{
  display = new Display;
}

void
KAHEngine::InitializeUI()
{
  uiManager = new UI::UIManager(display);
  UI::Label* label = uiManager->CreateLabel();
  label->SetText("This is only a test!");
}
