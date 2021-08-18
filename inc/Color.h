#ifndef __COLOR_H__
#define __COLOR_H__

#include "KString.h"

#include <SDL.h>

class Color
{
  float r, g, b, a;

  /**
   * Normalize the channel values to appropriate range (0.0f-1.0f)
   */
  void Normalize();

public:
  Color()
    : r(0.0f)
    , b(0.0f)
    , g(0.0f)
    , a(0.0f){};
  Color(float r, float g, float b, float a);

  void Set(float r, float g, float b, float a);
  void Red(float r);
  void Green(float g);
  void Blue(float b);
  void Alpha(float a);

  float Red() { return r; }
  float Green() { return g; }
  float Blue() { return b; }
  float Alpha() { return a; }

  // TODO: This is poor design
  SDL_Color* ConvertToSDLColor(SDL_Color* sdlColor) const;

  static Color FromHex(KString const& hexString);

  static Color Black;
};

#endif // __COLOR_H__