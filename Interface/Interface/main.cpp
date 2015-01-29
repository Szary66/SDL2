#include "SDL_ttf.h"
#include <cstdlib>
#include "Init.h"
#include "Window.h"
#define SDL_MAIN_HANDLED
#undef main
int main(){
	SDL_SetMainReady();
	if(SDL2::init(SDL_INIT_EVERYTHING))
		return EXIT_FAILURE;
	if(TTF_Init())
		return EXIT_FAILURE;
	SDL2::initSubSystem(SDL_INIT_EVERYTHING);

	SDL2::Display::Window w;
	w.create("My window", 800, 600);
	SDL_Renderer* r = SDL_CreateRenderer(w.get(), 0, SDL_RENDERER_ACCELERATED);
	SDL_Event e;


	do{
		SDL_RenderClear(r);
		SDL_PollEvent(&e);
		SDL_RenderPresent(r);
	} while(e.type != SDL_QUIT);


	//SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
	SDL_Quit();
	TTF_Quit();
	return EXIT_SUCCESS;
}
