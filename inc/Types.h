#ifndef __TYPES_H__
#define __TYPES_H__

#ifdef _MSC_VER
#define interface __interface
#else
#define interface class
#endif

typedef char I8;
typedef short I16;
typedef long I32;
typedef long long I64;

typedef unsigned char U8;
typedef unsigned short U16;
typedef unsigned long U32;
typedef unsigned long long U64;

#endif // __TYPES_H__
