#ifndef __OBJECT_H__
#define __OBJECT_H__


#include "Common.h"


class
Object
{

public:

  virtual U32
  Hash();

  virtual bool
  IsEqual(Object* other);

};



#endif // __OBJECT_H__
