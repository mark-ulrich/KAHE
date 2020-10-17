#include <SDL.h>

#include "Common.h"
#include "KAHEngine.h"
#include "Util.h"

#ifdef DEBUG
#undef SDL_ASSERT_LEVEL
#define SDL_ASSERT_LEVEL 3
#endif

KAHEngine* kahe;

#include "KString.h"
#include <stdio.h>
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