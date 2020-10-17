#ifndef __TRANSFORM2D_H__
#define __TRANSFORM2D_H__

#include "Vector2.h"

class Transform2D
{
  Vec2f position;
  Vec2f scale;
  float rotation;

public:
  Transform2D();

  void SetPosition(Vec2f const& position);
  void SetPosition(float x, float y);

  void SetRotation(float angle);
  void AddRotation(float angle);
};

#endif // __TRANSFORM2D_H__