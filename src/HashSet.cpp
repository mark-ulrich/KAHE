#include "HashSet.h"


const U32 HashSet::DefaultSize = 256;



static void
IncreaseCapacity(HashSet* set);


HashSet::HashSet(U32 capacity)
{
  this->capacity = capacity;

  data = new T[this->capacity];
}

void
HashSet::Add(T* value)
{
  // Return immediately if value already in set
  if (Has(value))   return;

  // Resize if necessary
  if (size+1 >= capacity)
    IncreaseCapacity();

  U32 hash = HashFunc(value, sizeof(T));

  // Find last node (append location)
  SetNode* lastNode = data[hash];
  if (lastNode)
  {
    while (lastNode->next)
    {
      lastNode = lastNode->next;
    }
  }

  // Insert node
  SetNode* newNode = new SetNode(value);
  lastNode->next = newNode;
}

void
HashSet::Remove(T* value)
{
  U32 hash = HashFunc<T>(value);

}

bool
HashSet::Has(T* value)
{
  U32 hash = HashFunc(value, sizeof(T));
  SetNode* node = data[value];
  while (node)
  {
    if (node->value == value)
    {
      return true;
    }
    node = node->next;
  }

  return false;
}

U32
HashSet::Size()
{
  return size;
}


void
HashSet::IncreaseCapacity()
{
  // Allocate new data buffer of double size, then copy old data over
  T* newData = new T[capacity<<1];
  SDL_memcpy(newData, data, size);

  // Free old buffer and reset pointer to new buffer
  SAFE_DELETE_ARRAY(data);
  data = newData;

  capacity <<= 1;
}