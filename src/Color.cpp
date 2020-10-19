#include <SDL.h>

#include "Color.h"
#include "Memory.h"
#include "Util/Math.h"

void
Color::Normalize()
{
  Util::Math::Clampf(r, 0.0f, 1.0f);
  Util::Math::Clampf(g, 0.0f, 1.0f);
  Util::Math::Clampf(b, 0.0f, 1.0f);
  Util::Math::Clampf(a, 0.0f, 1.0f);
}

SDL_Color*
Color::ConvertToSDLColor(SDL_Color* sdlColor = nullptr)
{
  /*
    Note: This method can work in two ways, mostly because it seems
    like major overkill to create separate polymorphic mehods
    which serve a purpose which is specific to a specific library (SDL),
    and also will likely be moved/removed/etc in later refactoring

    For now, this method behaves in two possible ways:
      A) It receives as an argument a pointer to an SDL_Color object,
         which it fills in with the appropriate values before returning
         the same pointer to the same (modified) object.
      B) It receives a null pointer as argument, or no argument, in which
         case, the pointer defaults to nullptr. In this case, the method
         will allocate a *new* SDL_Color object before filling in the
         values as necessary, and finally it returns the freshly allocated
         object. Note this means the onus is on the caller to free the
         SDL_Color object.

    To clarify, this allows two possible use cases:

        // Create a mostly purple Color; convert to SDL_Color;
        // *free* the SDL_Color
        Color myColor(1.0f, 0.14f, 0.8f, 0.0f);
        SDL_Color* sdlColor = myColor.ConvertToSDLColor();
        SAFE_FREE(sdlColor);  // DON'T FORGET TO FREE!!!!

        Color myColor(1.0f, 0.0f, 0.0f, 0.0f);
        SDL_Color sdlColor;
        myColor.ConvertToSDLColor(&sdlColor);
  */

  if (!sdlColor)
  {
    sdlColor = (SDL_Color*)KMalloc(sizeof(SDL_Color));
  }
  SDL_assert(sdlColor != nullptr);

  // Note: SDL_Color expects individual channels to
  // be 8-bit. Since our Color class implementation
  // stores channels as percentages of maximum
  // (from 0.0-1.0), we scale by maximum 8-bit
  // value (0xff)

  sdlColor->r = r * 0xff;
  sdlColor->g = g * 0xff;
  sdlColor->b = b * 0xff;
  sdlColor->a = a * 0xff;
  return sdlColor;
}

Color::Color(float r, float g, float b, float a)
  : r(r)
  , g(g)
  , b(b)
  , a(a)
{
  Normalize();
}

void
Color::Set(float r, float g, float b, float a)
{
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  Normalize();
}

void
Color::Red(float r)
{
  this->r = r;
  Normalize();
}

void
Color::Green(float g)
{
  this->g = g;
  Normalize();
}

void
Color::Blue(float b)
{
  this->b = b;
  Normalize();
}

void
Color::Alpha(float a)
{
  this->a = a;
  Normalize();
}