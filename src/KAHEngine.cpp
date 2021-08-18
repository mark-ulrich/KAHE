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

void
KAHEngine::Run()
{
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
      if (ev.type == SDL_KEYUP && ev.key.keysym.sym == SDLK_ESCAPE)
      {
        isRunning = false;
        break;
      }
    }

    Renderer& renderer = display->Renderer();
    uiManager->Render(renderer);
    display->Present();
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
  display = new ::Display;
}

void
KAHEngine::InitializeUI()
{
  ASSERT(display);
  uiManager = new UI::UIManager(*display);
  UI::Label* label = uiManager->CreateLabel();
  label->SetFont(uiManager->GetFont("default"));
  label->SetText("This is only a test!");
}
