#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

#include <SDL.h>

#include "KString.h"
#include "Texture.h"

class TextureLoader
{
  static SDL_Renderer* renderer;

public:
  static void SetRenderer(SDL_Renderer* renderer);

  static Texture* Load(KString const& path);
};

#endif // __TEXTURELOADER_H__
