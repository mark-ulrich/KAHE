#ifndef __KSTRING_H__
#define __KSTRING_H__

#include <stdarg.h>

#include "Types.h"

class KString
{
  char* buffer;
  U32 length;

public:
  KString();
  KString(char const str[]);
  KString(KString const& str);
  ~KString();

  KString& Append(KString const& other);

  U32 Length() const;
  char* CString() const;

  static KString Format(char const* fmt, ...);

  KString& operator=(KString const& other);

  // friend KString operator+(char const* lhs, KString const& rhs);
};

// KString
// operator+(char const* lhs, KString const& rhs)
// {
//   KString newString = lhs;
//   newString.Append(rhs);
//   return newString;
// }

#endif // __KSTRING_H__