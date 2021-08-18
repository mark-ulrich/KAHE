#include "UI\Label.h"
#include "KAHEngine.h"

#include <SDL_ttf.h>

extern KAHEngine* kahe;

namespace UI {

Label::Label(UIManager* uiManager, KString const& text)
{
  this->uiManager = uiManager;
  font = uiManager->GetDefaultFont();
  SetText(text);
}

void
Label::SetText(KString const& text)
{
  this->text = text;
  UpdateTexture();
}

void
Label::Render(Renderer& renderer)
{
  SDL_Rect dstRect = {};
  SDL_QueryTexture(
    texture.GetTexturePointer(), NULL, NULL, &dstRect.w, &dstRect.h);
  SDL_RenderCopyEx(renderer.GetSDLRenderer(),
                   texture.GetTexturePointer(),
                   NULL,
                   &dstRect,
                   transform.Rotation(),
                   NULL,
                   SDL_FLIP_NONE);
}

void
Label::SetPosition(Vec2f const& position)
{
  transform.SetPosition(position);
}

void
Label::SetFont(Font* font)
{
  ASSERT(font);
  this->font = font;
}

void
Label::UpdateTexture()
{
  if (text.Length() == 0)
    return;
  if (!font)
    return;

  // TODO: Testing color
  textColor.Set(1.0f, 0.0f, 0.0f, 0.0f);
  SDL_Color sdlColor;
  textColor.ConvertToSDLColor(&sdlColor);

  TTF_Font* sdlFont = font->GetTTFFont();
  SDL_Surface* labelSurface =
    TTF_RenderText_Solid(sdlFont, text.CString(), sdlColor);
  if (!labelSurface)
  {
  }
  // ASSERT(labelSurface);
  ASSERT(uiManager != nullptr);
  SDL_Texture* labelTexture = SDL_CreateTextureFromSurface(
    kahe->Display().Renderer().GetSDLRenderer(), labelSurface);

  ASSERT(labelTexture);
  SDL_FreeSurface(labelSurface);

  SDL_DestroyTexture(texture.GetTexturePointer());
  texture.SetTexturePointer(labelTexture);
}

}