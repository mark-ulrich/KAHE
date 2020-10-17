#include "UI/UIManager.h"
#include "UI/Label.h"

#include <stdio.h>

namespace UI {

void
UIManager::ShowCursor(bool show)
{
  isCursorVisible = show;
}

Label*
UIManager::CreateLabel()
{
  Label* label = new Label(this);
  widgets.Append(label);
  return label;
}

void
UIManager::Render()
{
  static SDL_Renderer* renderer = display->GetRenderer();

  U32 count = 0;
  for (auto widget : widgets)
  {
    // printf("Widget: %02d\n", count++);
    widget->Render();
  }
}

} // namespace UI