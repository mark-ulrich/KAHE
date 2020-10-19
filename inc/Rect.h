#include "Types.h"

// TODO: Move to own header
template<typename T>
struct Rect
{
  T x, y, w, h;
};
typedef Rect<I32> Recti;
typedef Rect<float> Rectf;