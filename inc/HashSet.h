#ifndef __HASHSET_H__
#define __HASHSET_H__


template <typename T>
class
HashSet
{

  static const U32 DefaultSize;

  U32 size      = 0;
  U32 capacity  = 0;

  T* data = nullptr;
  
  void
  IncreaseCapacity();


public:

  HashSet(U32 capacity = DefaultSize);
  ~HashSet();

  void
  Add(T* value);

  bool
  Has(T* value);

  void
  Remove(T* value);

  U32
  Size();

};


#endif // __HASHSET_H__
