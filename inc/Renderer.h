#ifndef __RENDERER_H__
#define __RENDERER_H__

#include <SDL.h>
#include <list>
#include <memory>

#include "Color.h"
#include "Texture.h"
#include "Util.h"

struct RenderNode;

class Renderer
{
  using RenderNodePtr = std::unique_ptr<RenderNode>;
  using RenderNodeList = std::list<RenderNodePtr>;

  SDL_Renderer* sdlRenderer;

  std::list<RenderNodePtr> renderNodes;

public:
  Renderer(SDL_Window* window);
  ~Renderer();

  SDL_Renderer* GetSDLRenderer() { return sdlRenderer; }

  void Render();

  void SetDrawColor(Color const& color);

  void AddRenderNode(RenderNode* renderNode);
};

#endif // __RENDERER_H__
