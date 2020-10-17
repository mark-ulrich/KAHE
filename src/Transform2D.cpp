#include "Transform2D.h"

Transform2D::Transform2D() {}

void
Transform2D::SetPosition(Vec2f const& newPosition)
{
  position = newPosition;
}

void
Transform2D::SetPosition(float x, float y)
{
  position.x = x;
  position.y = y;
}

void
Transform2D::SetRotation(float angle)
{
  rotation = angle;
}

void
Transform2D::AddRotation(float angle)
{
  rotation += angle;
}