#ifndef __IITERATOR_H__
#define __IITERATOR_H__

#include "Types.h"

template<typename T>
interface IIterator
{
public:
  virtual bool operator==(IIterator<T> const&) const = 0;
  virtual bool operator!=(IIterator<T> const&) const = 0;
  virtual IIterator<T> const& operator++() = 0;
  virtual T const& operator*() = 0;
};

#endif // __IITERATOR_H__