#include <SDL_image.h>
#include <assert.h>

#include "Common.h"
#include "KAHEngine.h"
#include "TextureLoader.h"
#include "Util.h"

extern KAHEngine* kahe;

Renderer* TextureLoader::renderer = nullptr;

void
TextureLoader::SetRenderer(Renderer* renderer)
{
  TextureLoader::renderer = renderer;
}

Texture*
TextureLoader::Load(KString const& path)
{
  SDL_assert(kahe != nullptr);
  SDL_assert(TextureLoader::renderer);

  KString absolutePath = KString::Format(
    "%s/textures/%s", kahe->GetDataDirectory().CString(), path.CString());

  SDL_Texture* texture = nullptr;
  SDL_Surface* surface = IMG_Load(absolutePath.CString());
  if (surface)
  {
    texture = SDL_CreateTextureFromSurface(renderer->GetSDLRenderer(), surface);
    SDL_FreeSurface(surface);
  } else
  {
    fprintf(stderr, "%s\n", IMG_GetError());
    ERROR("Failed to load image: %s", path.CString());
  }
  return new Texture(texture);
}