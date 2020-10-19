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

  // TODO: Testing color
  textColor.Set(1.0f, 0.0f, 0.0f, 0.0f);
  SDL_Color sdlColor;
  textColor.ConvertToSDLColor(&sdlColor);

  SDL_Surface* labelSurface =
    TTF_RenderText_Solid(font, text.CString(), sdlColor);
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