#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL.h>

#include "Renderer.h"

using ImplTextureType = SDL_Texture*;

class Texture
{
  friend class Renderer;

  ImplTextureType texture;

public:
  Texture()
    : texture(nullptr)
  {}

  Texture(ImplTextureType texture)
    : texture(texture)
  {}

  ImplTextureType GetTexturePointer() { return texture; }
  void SetTexturePointer(ImplTextureType newTexture);
};

#endif // __TEXTURE_H__