#ifndef __UI_UIMANAGER_H__
#define __UI_UIMANAGER_H__

#include "Display.h"
#include "Font.h"
#include "KString.h"
#include "Renderer.h"
#include "Texture.h"
#include "TextureLoader.h"
#include "UI/Label.h"
#include "Vector2.h"

#include <list>
#include <map>

namespace UI {

class Widget;

class UIManager
{
  using WidgetList = std::list<Widget*>;
  using FontTable = std::map<KString, Font*>;

  ::Display& display;

  WidgetList widgets;
  FontTable fontTable;

  bool isCursorVisible;

  Vec2f cursorPosition;
  Texture* cursorTexture;

  void LoadDefaultFont();

public:
  UIManager(Display& display)
    : display(display)
  {
    // TODO: Maybe move to base engine or Display class
    if (!TTF_WasInit())
      TTF_Init();

    LoadDefaultFont();

    // SDL_ShowCursor(0);
    // cursorTexture = TextureLoader::Load("cursor.png");
  }

  void ShowCursor(bool show = true);

  ::Display& Display() { return display; }

  void LoadFont(KString const& name,
                KString const& path,
                Font::PointSizeType size);

  Font* GetFont(KString const& name);
  Font* GetDefaultFont();

  LabelPtr CreateLabel();
  LabelPtr CreateLabel(KString const& text);

  void SetCursorPosition(Vec2f const& newPosition);
  void UpdateCursorPosition(Vec2f const& deltaPosition);

  void Render(Renderer& renderer);
};

}

#endif // __UI_UIMANAGER_H__