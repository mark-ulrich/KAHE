#ifndef __DISPLAY_H__
#define __DISPLAY_H__

#include <SDL.h>

#include "Renderer.h"
#include "Types.h"

class Renderer;

class Display
{
  static const U32 DefaultWidth;
  static const U32 DefaultHeight;

  SDL_Window* sdlWindow;
  Renderer* renderer;

public:
  Display();
  ~Display();
};

#endif // __DISPLAY_H__