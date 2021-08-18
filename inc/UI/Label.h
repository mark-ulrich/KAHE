#ifndef __UI_LABEL_H__
#define __UI_LABEL_H__

#include "Color.h"
#include "Font.h"
#include "KString.h"
#include "Renderer.h"
#include "Widget.h"


#include <SDL.h>
#include <SDL_ttf.h>

#include <memory>

namespace UI {

class Label : public Widget
{
  KString text;
  Font* font;

  Color textColor;

public:
  Label::Label(UIManager* uiManager)
    : Label(uiManager, "")
  {}

  Label(UIManager* uiManager, KString const& text);

  virtual void Render(Renderer& renderer);

  virtual void SetText(KString const& text);
  virtual void SetPosition(Vec2f const& position);
  void SetFont(Font* font);

  virtual void UpdateTexture();
};

using LabelPtr = Label*;

}

#endif // __UI_LABEL_H__