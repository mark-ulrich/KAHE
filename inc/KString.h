#ifndef __KSTRING_H__
#define __KSTRING_H__

#include "Types.h"

#include <cstdarg>
#include <ostream>
#include <string>

class KString
{
  char* buffer;
  U32 length;

public:
  KString();
  KString(KString const& str);
  KString(char const str[]);
  KString(std::string const& str)
    : KString(str.c_str())
  {}
  KString(U32 size);
  ~KString();

  KString& Append(KString const& other);

  U32 Length() const;
  char* CString() const;

  static KString Format(char const* fmt, ...);

  KString SubString(U32 beginIndex, U32 length) const;

  // ======================================
  //           Operators
  // ======================================

  KString& operator=(KString const& other);

  char operator[](I32 index) const;
  char& operator[](I32 index);
  friend bool operator==(KString const& me, KString const& other);
  friend bool operator!=(KString const& me, KString const& other);
  friend bool operator<(KString const& me, KString const& other);
  friend bool operator>(KString const& me, KString const& other);

  friend std::ostream& operator<<(std::ostream& os, KString const& str);

  // friend KString operator+(char const* lhs, KString const& rhs);

  // ======================================
  //           Iterator
  // ======================================
  class Iterator
  {
    char elem;

  public:
    Iterator(char elem)
      : elem(elem)
    {}
  };

  Iterator begin()
  {
    if (length == 0)
    {
      return Iterator('\0');
    } else
    {
      return Iterator(buffer[0]);
    }
  }

  static KString Empty;
};

// KString
// operator+(char const* lhs, KString const& rhs)
// {
//   KString newString = lhs;
//   newString.Append(rhs);
//   return newString;
// }

#endif // __KSTRING_H__