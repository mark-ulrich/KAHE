#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SDL.h>

#include "Types.h"

class Display
{
  static const U32 DefaultWidth;
  static const U32 DefaultHeight;

  SDL_Window* sdlWindow;
  SDL_Renderer* sdlRenderer;

public:
  Display();
  ~Display();

  void Render();

  SDL_Renderer* GetRenderer() { return sdlRenderer; }
};

#endif // __DISPLAY_H__