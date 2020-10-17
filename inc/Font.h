#ifndef __FONT_H__
#define __FONT_H__

#include <SDL_ttf.h>

using ImplFontType = TTF_Font;

class Font
{
  ImplFontType* font;

public:
  Font();
};

#endif // __FONT_H__