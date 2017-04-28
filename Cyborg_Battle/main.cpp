#include "cleanup.h"
#include "res_path.h"
#include "drawing_functions.h"
#include "SDL_mixer.h"

int main(int argc, char **agv)
{
	// setup SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		cout << "error initialising SDL" << endl;
		return 1;
	}

	// setup window
	SDL_Window *window = SDL_CreateWindow("Cyborg Battle", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 352, SDL_WINDOW_SHOWN); // SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN
	if (window == nullptr)
	{
		SDL_Quit();
		cout << "window error" << endl;
	}

	// setup renderer
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr)
	{
		cleanup(window);
		SDL_Quit();
		cout << "renderer error" << endl;
		return 1;
	}

	// this is the size to draw things at, before we scale it to the screen size dimensions mentioned in createWindow
	SDL_RenderSetLogicalSize(renderer, 640, 352);

	// initialise sdl_image
	if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		SDL_Quit();
		cout << "SDL image did not initiliase" << endl;
		return 1;
	}

	// initialise text to font
	if (TTF_Init() != 0)
	{
		SDL_Quit();
		cout << "SDL TTF did not initialise" << endl;
		return 1;
	}

	// initialise mixer
	if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
	{
		SDL_Quit();
		cout << "SDL Mixer did not initialise" << endl;
		return 1;
	}

	// load up a texture to draw
	string resPath = getResourcePath();
	SDL_Texture* texture = loadTexture(resPath + "map.png", renderer);

	// run game for 5000 ticks (5000ms)
	while (SDL_GetTicks() < 5000)
	{
		// clear the screen
		SDL_RenderClear(renderer);
		// draw what we want to the renderer
		renderTexture(texture, renderer, 0, 0);
		// display rendered image
		SDL_RenderPresent(renderer);
	}

	cleanup(renderer);
	cleanup(window);
	cleanup(texture);

	SDL_Quit();
	return 0;

}