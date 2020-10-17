#include <SDL.h>
#include <stdarg.h>


#include "Types.h"



/**
  TODO: Build a system-specific filesystem path from the
  given strings
*/
char*
MakePath(char* root, ...)
{
  va_list args;
  va_start(args, root);
  
  va_end(args);
  return NULL;
}


U32
HashString(char* string)
{
  U32 hash, slen;
  hash = slen = SDL_strlen(string);
  for (int i = 0;
       i < slen;
       ++i)
  {
    hash *= string[i] * i;
  }
  return hash;
}
