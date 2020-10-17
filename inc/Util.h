#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>

#include "Util.h"
#include "Types.h"


#define SAFE_DELETE(p)        { if (p) { delete (p); (p)=nullptr; } }
#define SAFE_DELETE_ARRAY(p)  { if (p) { delete[] (p); (p)=nullptr; } }

#define FATAL(errMsg, __VA_ARGS__) \
  { \
    fprintf(stderr, "FATAL: " errMsg, __VA_ARGS__); \
    exit(-1); \
  }

#define ERROR(errMsg, __VA_ARGS__) \
  { \
    fprintf(stderr, "ERROR: " errMsg, __VA_ARGS__); \
  }


char*
MakePath(char* root, ...);

U32
HashString(char* string);


#endif // __UTIL_H__
