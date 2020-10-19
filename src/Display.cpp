#include <SDL.h>

#include "Common.h"
#include "Display.h"
#include "KAHEngine.h"
#include "TextureLoader.h"

extern KAHEngine kahe;

const U32 Display::DefaultWidth = 800;
const U32 Display::DefaultHeight = 600;

Display::Display()
{
  SDL_Init(SDL_INIT_VIDEO);

  // Create main window
  sdlWindow = SDL_CreateWindow("kahe",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               DefaultWidth,
                               DefaultHeight,
                               0 // SDL_WindowFlags
  );

  if (!sdlWindow)
  {
    FATAL("SDL_CreateWindow", NULL);
  }

  // Create renderer
  renderer = new Renderer(sdlWindow);

  // TextureLoader::SetRenderer(sdlRenderer);

  // Set default background color
  // SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
}

Display::~Display()
{
  SDL_DestroyWindow(sdlWindow);
}

void
Display::Render()
{
  renderer->Render();
}