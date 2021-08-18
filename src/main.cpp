#include "Common.h"
#include "KAHEngine.h"
#include "KString.h"
#include "Util.h"

#include <SDL.h>

#include <iostream>

#define USE_SDL

#ifdef DEBUG
#ifdef USE_SDL
#undef SDL_ASSERT_LEVEL
#define SDL_ASSERT_LEVEL 3
#endif // USE_SDL
#endif // DEBUG

// Global engine object
inline KAHEngine* kahe;

int
main(int argc, char* argv[])
{
  kahe = new KAHEngine;
  kahe->InitializeDisplay();
  kahe->InitializeUI();
  kahe->Run();
  SAFE_DELETE(kahe);
  return 0;
}