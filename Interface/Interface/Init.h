#pragma once
#include "SDL.h"
/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Inicjalize the SDL2 
	*@param Uint32 flag to initcialize
	*@return bool true if initcialized or false if can't*/
	bool inline init(Uint32 flag){
		return !SDL_Init(flag);
	}

	/*Inicjalize the subSystem SDL2
	*@param Uint32 flag to initcjalize
	*@return bool true if initcialized or false if can't*/
	bool inline initSubSystem(Uint32 flag){
		return !SDL_InitSubSystem(flag);
	}

	/*This is called by the real main funcion to let the rest of the
	*Define SDL_MAIN_GANDLED id been not defined*/
	void inline setMainReady(){
	#ifndef SDL_MAIN_HANDLED
	#define SDL_MAIN_HANDLED
	#endif
		SDL_SetMainReady();
	}

	/*Returns a mask of the specified subsystem which have previous been inicialized
	*@param Uint32 flag to check 
	*@return Uint32 mask*/
	Uint32 inline wasInit(Uint32 flag){
		return SDL_WasInit(flag);
	}

	/*Clean up inicialized SDL system*/
	void inline quit(){
		SDL_Quit();
	}

	/*Clean up specific inicialized SDL sub system
	*Uint32 flag to clean*/
	void inline quitSubSystem(Uint32 flag){
		SDL_QuitSubSystem(flag);
	}
}