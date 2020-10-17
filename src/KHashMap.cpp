#include <SDL.h>
#include <string.h>

#include "KHashMap.h"
#include "Util.h"

class KMapNode
{

  friend class KHashMap;

  char* key;
  void* value;
  KMapNode* next;

public:
  KMapNode()
    : KMapNode(nullptr, nullptr)
  {}

  KMapNode(char* key, void* value)
    : key(key)
    , value(value)
    , next(nullptr)
  {}
};

KHashMap::KHashMap() {}

KHashMap::~KHashMap() {}

void
KHashMap::Put(char* key, void* value)
{
  KMapNode* target = map[HashString(key)];

  // Find first non-null node at index
  if (target)
  {
    while (target->next)
    {
      target = target->next;
    }
  }

  target->next = new KMapNode(key, value);
}

void*
KHashMap::Get(char* key)
{
  return SearchKey(key);
}

/**
  Searches the map for a given key; if found, returns
  the associated value; if not found, returns NULL
*/
void*
KHashMap::SearchKey(char* key)
{
  KMapNode* node = map[HashString(key)];

  // If we have a valid hash index: is it the correct entry?
  while (node && strncmp(key, node->key, strlen(key)) != 0)
  {
    node = node->next;
    if (!node)
      break;
  }

  return node->value;
}

bool
KHashMap::HasKey(char* key)
{
  return SearchKey(key) ? true : false;
}
