#pragma once
#include <memory>
#include <string>
#include "SDL_image.h"
#include "Renderer.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to Graphics share and manipulation*/
	namespace Graphic{
		/*Class with source image */
		class Source{
		public:
			Source(const Source&) = delete;
			Source(Source&) = delete;
			Source(const std::string& path, const SDL2::Display::Renderer& renderer){
				if(!(_surface = SDL_LoadBMP(path.c_str()))){
					std::cout << "Error with load SDL_Surface: " << SDL_GetError() << std::endl;
					return;
				}
				if(!(_texture = SDL_CreateTextureFromSurface(renderer.get(), _surface))){
					std::cout << "Error with load SDL_Texture: " << SDL_GetError() << std::endl;
					return;
				}
				realSizeTexture();
			}
			~Source(){
				SDL_FreeSurface(_surface);
				SDL_DestroyTexture(_texture);
			}

			size_t inline width()const{
				return _width;
			}

			size_t inline height()const{
				return _height;
			}

			SDL_Surface* surface()const{
				return _surface;
			}

			SDL_Texture* texture()const{
				return _texture;
			}
		protected:
			SDL_Surface* _surface;
			SDL_Texture* _texture;
		private:
			size_t _width;
			size_t _height;

			void realSizeTexture(){
				int w, h;
				SDL_QueryTexture(_texture, nullptr, nullptr, &w, &h);
				_width = w;
				_height = h;
			}
		};

		struct Sprite:public Source{
			Sprite(const std::string& path, const SDL2::Display::Renderer& renderer)
			:Source(path, renderer){
				rectSource = {0, 0, (int)width(), (int)height()};
				rectShowed = rectSource;
			}

			SDL_Rect rectShowed;
			SDL_Rect rectSource;
		};
	}
}
