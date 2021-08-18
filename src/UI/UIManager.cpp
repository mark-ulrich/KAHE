#include "UI/UIManager.h"
#include "UI/Label.h"

namespace UI {

void
UIManager::ShowCursor(bool show)
{
  isCursorVisible = show;
}

LabelPtr
UIManager::CreateLabel(KString const& text)
{
  LabelPtr label = new Label(this, text);
  widgets.push_back(label);
  return label;
}

LabelPtr
UIManager::CreateLabel()
{
  return UIManager::CreateLabel("");
}

void
UIManager::LoadFont(KString const& name,
                    KString const& path,
                    Font::PointSizeType size)
{
  if (fontTable.find(name) != fontTable.end())
  {
    return;
  }
  fontTable[name] = new Font(path, size);
}

void
UIManager::LoadDefaultFont()
{
  fontTable["default"] =
    new Font("g:\\kahe\\data\\fonts\\Roboto-Regular.ttf", 36);
}

Font*
UIManager::GetFont(KString const& name)
{
  auto& iter = fontTable.find(name);
  if (iter == fontTable.end())
  {
    ASSERT(false);
    return nullptr;
  }
  return iter->second;
}

Font*
UIManager::GetDefaultFont()
{
  ASSERT(fontTable.empty() == false);
  return fontTable.begin()->second;
}

void
UIManager::Render(Renderer& renderer)
{
  for (auto widget : widgets)
  {
    widget->Render(renderer);
  }
}

} // namespace UI