#pragma once
#include <string>
#include <iostream>
#include "SDL.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to manipulation screen*/
	namespace Display{
		/*Class with basic parameter to window*/
		class Window{
		public:
			/*Delete the copy construktors*/
			Window(const Window&) = delete;
			Window(Window&) = delete;
	
			/*Constructor: create window
			*@param const char* to name window
			*@param Uint32 width window
			*@param UINT32 height window
			*@param Uint32 x to left up corner
			*@param Uint32 y to left up corner
			*@param Uint32 SDL_WindowFlag
			*@return bool true if created successful or false if was fail*/
			Window(const char* name, Uint32 w, Uint32 h, Uint32 x = SDL_WINDOWPOS_UNDEFINED, Uint32 y = SDL_WINDOWPOS_UNDEFINED, Uint32 flag = SDL_WINDOW_SHOWN)
				:_width(w), _height(h), _window(nullptr){
				if(!(_window = SDL_CreateWindow(name, x, y, w, h, flag)))
					std::cout << "Window create error: " << SDL_GetError() << std::endl;
			};

			/*Constructor: create window of fullcreen
			*@param const char* to name window
			*@param Uint32 SDL_WindowFlag
			*@return bool true if created successful or false if was fail*/
			Window(const char* name, Uint32 flag = SDL_WINDOW_FULLSCREEN_DESKTOP){
				if(!(_window = SDL_CreateWindow(name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0, flag)))
					std::cout << "Window create error: " << SDL_GetError() << std::endl;
			}

			/*Destroy window*/
			~Window(){
				SDL_DestroyWindow(_window);
			}

			/*SDL_Window getter
			*@return SDL_Window* */
			inline SDL_Window* const get()const{
				return _window;
			}

			/*Width getter
			*@return size_t width window*/
			inline size_t width()const{
				return _width;
			}

			/*Height getter
			*@return size_t height window*/
			inline size_t height()const{
				return _height;
			}
		private:
			SDL_Window* _window;

			size_t _width;
			size_t _height;
		};
	}
}
