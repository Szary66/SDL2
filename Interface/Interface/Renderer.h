#pragma once
#include <memory>z
#include "SDL_render.h"
#include "SDL_rect.h"
#include "Window.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to manipulation screen*/
	namespace Display{
		class Renderer{
		public:
			/*Renderer constructor copy = delete*/
			Renderer(const Renderer&) = delete;
			Renderer(Renderer&) = delete;
			
			/*Constructor: create renderer
			*@param const Window refence on the will be set renderer
			*@param SDL_RendererFlags flag to renderer*/
			Renderer(const Window& window, SDL_RendererFlags flag = SDL_RENDERER_ACCELERATED){
				if(!(_renderer = SDL_CreateRenderer(window.get(), 0, flag))){
					std::cout << "Renderer create error: " << SDL_GetError() << std::endl;
				}
			}

			/*Destroy renderer*/
			~Renderer(){
				SDL_DestroyRenderer(_renderer);
			}

			/*Get renderer pointer
			*@return const SDL_Renderer*/
			inline SDL_Renderer* const get()const{
				return _renderer;
			}

			bool inline copy(SDL_Texture* texture, SDL_Rect* rTexture, SDL_Rect* rSprite){
				return !SDL_RenderCopy(_renderer, texture, rTexture, rSprite);
			}

			bool inline copyEx(SDL_Texture* texture, const SDL_Rect* rTexture, const SDL_Rect* rSprite, const SDL_Point* center, const SDL_RendererFlip flip, const double angle){
				return !SDL_RenderCopyEx(_renderer, texture, rTexture, rSprite, angle, center, flip);
			}
			/*Clear buffor renderer
			*@return bool true if succes cleared or false if not*/
			bool inline clear(){
				return !SDL_RenderClear(_renderer);
			}

			/*Present renderer on screen*/
			void inline present()const {
				SDL_RenderPresent(_renderer);
			}
		private:
			SDL_Renderer* _renderer;
		};
	}
}