#ifndef __KAHENGINE_H__
#define __KAHENGINE_H__

#include <SDL.h>

#include "Display.h"
#include "KString.h"
#include "UI/UIManager.h"

#define MAX_PATH 1024

class KAHEngine
{
  Display* display;
  UI::UIManager* uiManager;

  bool isRunning;
  KString dataDirectory;

public:
  KAHEngine();
  ~KAHEngine();

  void Run();

  void SetDataDirectory(KString const& path);
  KString const& GetDataDirectory() { return dataDirectory; }

  void InitializeDisplay();
  void InitializeUI();

  Display* GetDisplay() { return display; }
};

#endif // __KAHENGINE_H__
