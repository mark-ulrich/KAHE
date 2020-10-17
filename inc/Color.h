#ifndef __COLOR_H__
#define __COLOR_H__

#include "Util/Math.h"

class Color
{
  float r, g, b, a;

  /**
   * Normalize the channel values to appropriate range (0.0f-1.0f)
   */
  void Normalize();

public:
  Color(float r, float g, float b, float a);
};

void
Color::Normalize()
{
  Util::Math::Clampf(r, 0.0f, 1.0f);
  Util::Math::Clampf(g, 0.0f, 1.0f);
  Util::Math::Clampf(b, 0.0f, 1.0f);
  Util::Math::Clampf(a, 0.0f, 1.0f);
}

Color::Color(float r, float g, float b, float a)
  : r(r)
  , g(g)
  , b(b)
  , a(a)
{
  Normalize();
}

#endif // __COLOR_H__