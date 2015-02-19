#include "SDL_ttf.h"
#include <cstdlib>
#include "Init.h"
#include "Renderer.h"
#include "Texture.h"
#include "Text.h"
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

void loop(){
	SDL2::Display::Window w("My window", 800, 600);
	SDL2::Display::Renderer r(w);
	SDL2::Graphic::Sprite s("../images/images_15.bmp", r);
	SDL2::Graphic::Text cout(r, "../images/text.ttf", "cos tam", 14, SDL_Color{0,0,255,255});

	cout.rect = {200,200,200,200};

	SDL_Event* e = new SDL_Event();
	SDL_SetRenderDrawColor(r.get(), 0, 0, 0, 255);
	do{
		r.clear();
		SDL_PollEvent(e);
		cout.input(r, e);
		r.copy(s);
		//r.copy(cout);
		r.present();
	} while(e->type != SDL_QUIT && e->key.keysym.sym != SDLK_ESCAPE);
	delete e;
}

int main(){	
	init();
	loop();	
	quit();
	return EXIT_SUCCESS;
}

