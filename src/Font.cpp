#include "Font.h"
#include "KString.h"
#include "Types.h"
#include "Util.h"

Font::Font(KString const& path, Font::PointSizeType size)
{
  font = TTF_OpenFont(path.CString(), size);
  if (!font)
  {
    FATAL("Failed to load font: %s", path.CString());
  }
}
