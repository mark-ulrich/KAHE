#include <SDL_ttf.h>

#include "KAHEngine.h"
#include "UI\Label.h"

namespace UI {

Label::Label(UIManager* uiManager)
{
  this->uiManager = uiManager;
  font = TTF_OpenFont("d:\\git\\kahe\\data\\fonts\\Roboto-Medium.ttf", 36);
}

Label::Label(UIManager* uiManager, KString const& text)
{
  SetText(text);
}

void
Label::SetText(KString const& text)
{
  this->text = text;
  UpdateTexture();
}

void
Label::Render()
{
  SDL_Renderer* renderer = uiManager->GetDisplay().GetRenderer();

  SDL_Rect destRect;
  destRect.x = 0;
  destRect.y = 0;
  SDL_QueryTexture(
    texture.GetTexturePointer(), NULL, NULL, &destRect.w, &destRect.h);

  SDL_RenderCopyEx(renderer,
                   texture.GetTexturePointer(),
                   NULL,
                   &destRect,
                   0.0,
                   NULL, // origin
                   SDL_FLIP_NONE);
}

void
Label::SetPosition(Vec2f const& position)
{
  transform.SetPosition(position);
}

void
Label::UpdateTexture()
{
  SDL_assert(font);

  SDL_Color color;
  color.r = 0xff;
  color.g = 0x00;
  color.b = 0x00;
  color.a = 0x00;

  SDL_Surface* labelSurface = TTF_RenderText_Solid(font, text.CString(), color);
  SDL_assert(labelSurface);
  SDL_assert(uiManager != nullptr);
  SDL_Texture* labelTexture = SDL_CreateTextureFromSurface(
    uiManager->GetDisplay().GetRenderer(), labelSurface);

  SDL_assert(labelTexture);
  SDL_FreeSurface(labelSurface);

  SDL_DestroyTexture(texture.GetTexturePointer());
  texture.SetTexturePointer(labelTexture);
}

}