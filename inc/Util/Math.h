#ifndef __UTIL_MATH_H__
#define __UTIL_MATH_H__

namespace Util {

namespace Math {

template<typename T>
T
Clamp(T value, T min, T max)
{
  if (value < min)
    return min;
  else if (value > max)
    return max;
  else
    return value;
}

auto Clampf = Util::Math::Clamp<float>;

} // namespace Math

} // namespace Util

#endif // __UTIL_MATH_H__