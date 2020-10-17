#include <SDL.h>
#include <string.h>

#include "KString.h"
#include "Types.h"
#include "Util.h"

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

KString::~KString()
{
  SAFE_DELETE_ARRAY(buffer);
}

KString&
KString::Append(KString const& other)
{
  length += other.Length();
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
  const U32 BufferSize = 4096;
  char buffer[BufferSize];

  va_list args;
  va_start(args, fmt);
  SDL_vsnprintf(buffer, BufferSize, fmt, args);
  va_end(args);
  return KString(buffer);
}

KString&
KString::operator=(KString const& other)
{
  length = other.Length();
  buffer = new char[length + 1];
  SDL_memset(buffer, 0, length + 1);
  strncpy(buffer, other.buffer, length);
  return *this;
}