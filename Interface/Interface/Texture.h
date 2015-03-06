#pragma once
#include <memory>
#include <string>
#include <iostream>
#include "SDL_image.h"
#include "SDL_render.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to Graphics share and manipulation*/
	namespace Graphic{
		
		/*Struct with size: width and height*/
		struct Size{
			size_t w;
			size_t h;
		};

		/*Class with source image */
		class Source{
		public:
			/*Load *.BMP and create texture from surface
			*@param const std::string path to file
			*@param SDL_Renderer pointer to create SDL_Texture*/
			Source(const std::string& path, SDL_Renderer* renderer){
				if(!(_surface = SDL_LoadBMP(path.c_str()))){
					std::cout << "Error with load SDL_Surface (BMP): " << SDL_GetError() << std::endl;
					return;
				}
				if(!(_texture = textureFromSurface(renderer))){
					std::cout << "Error with create texture from surface (BMP): " << SDL_GetError() << std::endl;
					return;
				}
				realSizeTexture();
			}

			/*Load images and create texture from surface
			*@param const std::string path to file
			*@param SDL_Renderer pointer to create SDL_Texture
			*@param bool image flag*/
			Source(const std::string& path, SDL_Renderer* renderer, bool img){
				if(!(_surface = IMG_Load(path.c_str()))){
					std::cout << "Error with load SDL_Surface (IMG): " << SDL_GetError() << std::endl;
					return;
				}
				if(!(_texture = textureFromSurface(renderer))){
					std::cout << "Error with create texture from surface (IMG): " << SDL_GetError() << std::endl;
					return;
				}
			}
			~Source(){
				SDL_FreeSurface(_surface);
				SDL_DestroyTexture(_texture);
			}

			/*Size getter
			*@return Size oryginal width texture*/
			Size inline size()const{
				return _size;
			}

			/*SDL_surface pointer getter
			*@return SDL_Surface pointer*/
			SDL_Surface* surface()const{
				return _surface;
			}

			/*SDL_Texture pointer getter
			*@return SDL_Texture pointer*/
			SDL_Texture* texture()const{
				return _texture;
			}
		protected:
			SDL_Surface* _surface;
			SDL_Texture* _texture;
		private:
			Size _size;

			void realSizeTexture(){
				int w, h;
				SDL_QueryTexture(_texture, nullptr, nullptr, &w, &h);
				_size = {(size_t)w, (size_t)h};
			}

			inline SDL_Texture* textureFromSurface(SDL_Renderer* renderer){
				return SDL_CreateTextureFromSurface(renderer, _surface);
			}
		};

		/*Struct with source rect and showed rect*/
		struct Sprite: public Source{
			/*Load BMP and create sprite
			*@param const std::string path to file image
			*@param SDL_Renderer pointer to create texture*/
			//Sprite(const std::string& path, SDL_Renderer* renderer)
			//	:Source(path, renderer){
			//	rectShowed = rectSource = {0, 0, (int)size().w, (int)size().h};
			//}

			///*Load BMP and create sprite
			//*@param const std::string path to file image
			//*@param SDL_Renderer pointer to create texture
			//*@param bool set true*/
			//Sprite(const std::string& path, SDL_Renderer* renderer, bool flag)
			//	:(path, renderer, flag){
			//		rectShowed = rectSource = {0, 0, (int)size().w, (int)size().h};
			//}
			Sprite(Source source)
				:Source(source){}

			SDL_Rect rectShowed;
			SDL_Rect rectSource;
		};
	}
}