#include <SDL_ttf.h>
#include <cstdlib>
#include "Init.h"
#include "Renderer.h"
#include "TextureSource.h"
#define SDL_MAIN_HANDLED
#undef main

bool init(){
	if(!SDL2::init(SDL_INIT_EVERYTHING))
		return false;
	SDL2::initSubSystem(SDL_INIT_EVERYTHING);

	if(TTF_Init())
		return false;
	return true;
}

void quit(){
	SDL2::quitSubSystem(SDL_INIT_EVERYTHING);
	SDL2::quit();
	TTF_Quit();
}

int main(){	
	init();

	SDL2::Display::Window w("My window", 800, 600);
	SDL2::Display::Renderer r(w);
	SDL2::Graphic::Sprite s("../images/images_15.bmp", r);

	SDL_Event* e = new SDL_Event();
	SDL_SetRenderDrawColor(r.get(), 0, 0, 255,255);
	do{
		r.clear();
		SDL_PollEvent(e);
		r.copy(s.texture(), &s.rectSource, &s.rectShowed);
		r.present();
	} while(e->type != SDL_QUIT);

	quit();
	return EXIT_SUCCESS;
}
