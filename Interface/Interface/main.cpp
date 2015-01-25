#include "SDL.h"
#include "SDL_ttf.h"
#include <cstdlib>
#include "Window.h"
#undef main
int main(){
	if(SDL_Init(SDL_INIT_EVERYTHING))
		return EXIT_FAILURE;
	if(TTF_Init())
		return EXIT_FAILURE;

	SDL2::Display::Window w;
	w.create("My window", 800, 600);
	SDL_Renderer*  r = SDL_CreateRenderer(w.get(), 0, SDL_RENDERER_ACCELERATED);
	SDL_Event e;

	do{
		SDL_PollEvent(&e);
	} while(e.type != SDL_QUIT);

	SDL_Quit();
	TTF_Quit();
	return EXIT_SUCCESS;
}