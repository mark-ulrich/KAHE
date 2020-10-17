#ifndef __UI_IWIDGET_H__
#define __UI_IWIDGET_H__

#include "Types.h"

namespace UI {

interface IWidget
{
public:
  virtual void Render() = 0;
};

};

#endif // __UI_IWIDGET_H__