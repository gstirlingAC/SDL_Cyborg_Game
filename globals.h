#ifndef GLOBALS
#define GLOBALS

#include <string>
#include <iostream>
#include <SDL.h>

class Globals
{
public:
	//math helpers
	static const float PI;

	//useful for me as a dev
	static bool debugging;

	// SDL related
	static int ScreenWidth, ScreenHeight, ScreenScale, ScreenWidthScaled, ScreenHeightScaled;
	static SDL_Renderer* renderer;
};

#endif // !GLOBALS
