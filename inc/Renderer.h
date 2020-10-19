#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL.h>

#include "Util.h"

class Renderer
{
  SDL_Renderer* sdlRenderer;

public:
  Renderer(SDL_Window* window);
  ~Renderer();

  void Render();
};

#endif // __RENDERER_H__
