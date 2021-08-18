#include "KString.h"
#include "Types.h"
#include "Util.h"

#include <SDL.h>

#include <algorithm>
#include <cstring>
#include <ostream>
#include <stdexcept>

KString KString::Empty = "";

KString::KString()
{
  length = 0;
  buffer = new char[1];
  buffer[0] = '\0';
}

KString::KString(char const* str)
{
  length = SDL_strlen(str);
  buffer = new char[length + 1];
  SDL_memset(buffer, 0, length + 1);
  strncpy(buffer, str, length);
}

KString::KString(KString const& str)
{
  *this = str;
}

KString::KString(U32 size)
{
  length = size;
  buffer = new char[size + 1];
  SDL_memset(buffer, '\0', size + 1);
}

KString::~KString()
{
  SAFE_DELETE_ARRAY(buffer);
}

KString&
KString::Append(KString const& other)
{
  length += other.length;
  char* newBuffer = new char[length + 1];

  SDL_snprintf(newBuffer, length + 1, "%s%s", buffer, other.buffer);

  SAFE_DELETE_ARRAY(buffer);
  buffer = newBuffer;

  return *this;
}

U32
KString::Length() const
{
  return length;
}

char*
KString::CString() const
{
  return (buffer) ? buffer : "";
}

KString
KString::Format(char const* fmt, ...)
{
  const U32 BufferSize = 0x1000; // 4KB
  char buffer[BufferSize];

  va_list args;
  va_start(args, fmt);
  SDL_vsnprintf(buffer, BufferSize, fmt, args);
  va_end(args);
  return KString(buffer);
}

KString
KString::SubString(U32 beginIndex, U32 length) const
{
  if (beginIndex > this->length - 1)
  {
    return KString::Empty;
  }

  KString ret(length);
  for (int i = 0; i < length; ++i)
  {
    ret[i] = buffer[beginIndex + i];
  }
  return ret;
}

KString&
KString::operator=(KString const& other)
{
  length = other.length;
  buffer = new char[length + 1];
  SDL_memset(buffer, 0, length + 1);
  strncpy(buffer, other.buffer, length);
  return *this;
}

char
KString::operator[](I32 index) const
{
  if (index > length - 1 || index < 0 - static_cast<I32>(length))
  {
    return '\0';
  }
  else if (index >= 0)
  {
    return buffer[index];
  }
  else
  {
    // Negative index (index back to front)
    I32 realIndex = Length() + 1 + index;
    return buffer[realIndex];
  }
}

char&
KString::operator[](I32 index)
{
  if (index > length - 1 || index < 0 - static_cast<I32>(length))
  {
    throw new std::range_error("index out of range");
  }
  else if (index >= 0)
  {
    return buffer[index];
  }
  else
  {
    // Negative index (index back to front)
    I32 realIndex = Length() + 1 + index;
    return buffer[realIndex];
  }
}

bool
operator==(KString const& lhs, KString const& rhs)
{
  return ::SDL_strncmp(
           lhs.buffer, rhs.buffer, std::min(lhs.length, rhs.length)) == 0;
}

bool
operator!=(KString const& lhs, KString const& rhs)
{
  return ::SDL_strncmp(
           lhs.buffer, rhs.buffer, std::min(lhs.length, rhs.length)) != 0;
}

bool
operator<(KString const& lhs, KString const& rhs)
{
  return ::SDL_strncmp(
           lhs.buffer, rhs.buffer, std::min(lhs.length, rhs.length)) < 0;
}

bool
operator>(KString const& lhs, KString const& rhs)
{
  return ::SDL_strncmp(
           lhs.buffer, rhs.buffer, std::min(lhs.length, rhs.length)) > 0;
}

std::ostream&
operator<<(std::ostream& os, KString const& str)
{
  return os << str.CString();
}