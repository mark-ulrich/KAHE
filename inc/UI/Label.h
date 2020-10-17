#ifndef __UI_LABEL_H__
#define __UI_LABEL_H__

#include <SDL.h>
#include <SDL_ttf.h>

#include "Color.h"
#include "KString.h"
#include "Widget.h"

namespace UI {

class Label : public Widget
{
  KString text;
  TTF_Font* font;

  Color textColor;

public:
  Label(UIManager* uiManager);
  Label(UIManager* uiManager, KString const& text);

  virtual void SetText(KString const& text);

  virtual void Render();

  virtual void SetPosition(Vec2f const& position);

  virtual void UpdateTexture();
};

}

#endif // __UI_LABEL_H__