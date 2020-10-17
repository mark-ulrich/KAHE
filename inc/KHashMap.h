#ifndef __KHASHMAP_H__
#define __KHASHMAP_H__

#include "Common.h"

class KMapNode;

class KHashMap
{

  KMapNode* map[256];
  U32 size;

public:
  KHashMap();
  ~KHashMap();

  void Put(char* key, void* value);

  void* Get(char* key);

  bool HasKey(char* key);

  void* SearchKey(char* key);
};

#endif // __KHASHMAP_H__
