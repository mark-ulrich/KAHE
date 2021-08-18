#include "Renderer.h"
#include "Transform2D.h"

using std::shared_ptr;
using std::unique_ptr;

struct RenderNode
{
  Texture* texture;
  Transform2D* transform;
  I8 zIndex;
};

Renderer::Renderer(SDL_Window* sdlWindow)
{
  sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
  if (!sdlRenderer)
  {
    FATAL("SDL_CreateRenderer", NULL);
  }
}

Renderer::~Renderer()
{
  SDL_DestroyRenderer(sdlRenderer);
}

void
Renderer::Render()
{
  SDL_RenderClear(sdlRenderer);
  for (auto& renderNode : renderNodes)
  {
    SDL_Texture* sdlTexture = renderNode->texture->texture;
    ASSERT(renderNode->transform);
    Transform2D& transform = *(renderNode->transform);
    SDL_Rect dstRect = {};
    SDL_QueryTexture(sdlTexture, NULL, NULL, &dstRect.w, &dstRect.h);
    SDL_RenderCopyEx(sdlRenderer,
                     sdlTexture,
                     NULL,
                     &dstRect,
                     transform.Rotation(),
                     NULL,
                     SDL_FLIP_NONE);
  }
  SDL_RenderPresent(sdlRenderer);
}

void
Renderer::SetDrawColor(Color const& color)
{
  SDL_Color sdlColor;
  color.ConvertToSDLColor(&sdlColor);
  SDL_SetRenderDrawColor(
    sdlRenderer, sdlColor.r, sdlColor.g, sdlColor.b, sdlColor.a);
}

void
Renderer::AddRenderNode(RenderNode* renderNode)
{}