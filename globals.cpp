#include "globals.h"

const float Globals::PI = 3.14159;

//useful for me as a dev
bool Globals::debugging;

// SDL related
int Globals::ScreenWidth = 640, Globals::ScreenHeight = 352, Globals::ScreenScale = 2;
int Globals::ScreenWidthScaled = Globals::ScreenWidth*Globals::ScreenScale;
int Globals::ScreenHeightScaled = Globals::ScreenHeight*Globals::ScreenScale;
SDL_Renderer* Globals::renderer = NULL;