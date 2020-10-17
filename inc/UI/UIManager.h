#ifndef __UI_UIMANAGER_H__
#define __UI_UIMANAGER_H__

#include "Display.h"
#include "Font.h"
#include "KHashMap.h"
#include "KList.h"
#include "Texture.h"
#include "TextureLoader.h"
#include "UI/IWidget.h"
#include "UI/Label.h"
#include "Vector2.h"

namespace UI {

class UIManager
{
  Display* display;

  KList<Widget*> widgets;
  KHashMap fontTable;

  bool isCursorVisible;

  Vec2f cursorPosition;
  Texture* cursorTexture;

public:
  UIManager(Display* display)
    : display(display)
  {
    SDL_ShowCursor(0);
    cursorTexture = TextureLoader::Load("cursor.png");

    // TODO: Maybe move to base engine or Display class
    if (!TTF_WasInit())
      TTF_Init();
  }

  void ShowCursor(bool show = true);

  Display& GetDisplay() { return *display; }

  Label* CreateLabel();

  void Render();
};

}

#endif // __UI_UIMANAGER_H__