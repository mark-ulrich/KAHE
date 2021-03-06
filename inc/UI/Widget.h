#ifndef __WIDGET_H__
#define __WIDGET_H__

#include "Renderer.h"
#include "Texture.h"
#include "Transform2D.h"


namespace UI {

class UIManager;

class Widget
{
protected:
  UIManager* uiManager;
  Transform2D transform;
  Texture texture;

  /**
   * Update the Widget's texture based on state
   **/
  virtual void UpdateTexture() = 0;

public:
  Widget()
    : uiManager(nullptr)
  {
    // TODO: The Widget class should probably not
    // have a default constructor; however, annoying
    // compiler errors have persuaded me to add one
    // for the present time. This should be fixed/
    // troubleshot later
  }

  Widget(UIManager* uiManager)
    : uiManager(uiManager)
  {}

  virtual void Render(Renderer& renderer) = 0;
};

} // namespace UI

#endif // __WIDGET_H__