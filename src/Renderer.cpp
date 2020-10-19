#include "Renderer.h"

Renderer::Renderer(SDL_Window* sdlWindow)
{
  sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);

  if (!sdlRenderer)
  {
    FATAL("SDL_CreateRenderer", NULL);
  }
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(sdlRenderer);
}

void
Renderer::Render()
{
  // TODO: Implement
}