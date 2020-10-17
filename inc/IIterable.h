#ifndef __IITERABLE_H__
#define __IITERABLE_H__

#include "IIterator.h"
#include "Types.h"

interface IIterable
{
public:
  virtual IIterator& begin() = 0;
  virtual IIterator& end() = 0;
};

#endif // __IITERABLE_H__