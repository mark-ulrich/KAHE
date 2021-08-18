#ifndef __TEXTURELOADER_H__
#define __TEXTURELOADER_H__

#include <SDL.h>

#include "KString.h"
#include "Renderer.h"
#include "Texture.h"

class TextureLoader
{
  static Renderer* renderer;

public:
  static void SetRenderer(Renderer* renderer);

  static Texture* Load(KString const& path);
};

#endif // __TEXTURELOADER_H__
