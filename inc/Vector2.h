#ifndef __VECTOR2_H__
#define __VECTOR2_H__

template<typename T>
struct Vector2
{
  T x, y;

  Vector2();
};

template<typename T>
Vector2<T>::Vector2()
{
  x = 0.0f;
  y = 0.0f;
}

typedef Vector2<float> Vec2f;

#endif // __VECTOR2_H__