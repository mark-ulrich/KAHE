#ifndef __FONT_H__
#define __FONT_H__

#include "KString.h"
#include "Types.h"

#include <SDL_ttf.h>

class Font
{

public:
  using PointSizeType = I32;

private:
  TTF_Font* font;
  PointSizeType size;

public:
  Font()
    : font(nullptr)
  {}
  Font(KString const& path, PointSizeType size);
  ~Font();

  TTF_Font* GetTTFFont() { return font; }
};

#endif // __FONT_H__