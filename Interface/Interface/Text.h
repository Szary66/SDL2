#pragma once
#include <string>
#include <iostream>
#include "Color.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "Renderer.h"
/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Namespace with text manipulation*/
	namespace Text{
		class Source{
		public:
			Source(const std::string &path, const std::string &text, int size, const SDL_Color color)
				:_color(color), _surface(nullptr), _texture(nullptr){
				if(!(_font = TTF_OpenFont(path.c_str(), size)))
					std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
				else
					if(!(_surface = TTF_RenderText_Solid(_font, text.c_str(), _color)))
						std::cout<< "Error with load TTF: " << TTF_GetError() << std::endl;
				}
			
			Source(TTF_Font* font){}
			~Source(){
				TTF_CloseFont(_font);
			}

			SDL_Texture* texture()const{
				return _texture;
			}
		protected:
			TTF_Font* _font;
			SDL_Surface* _surface;
			SDL_Texture* _texture;
			SDL_Color _color;
		};

		class Output: public Source{
		public:
			Output(const Display::Renderer& renderer, const std::string &path, const std::string &text, int size, const SDL_Color color):
			Source(path, text, size, color), _message(text){
				if(!(_texture = SDL_CreateTextureFromSurface(renderer.get(), _surface)))
					std::cout << "Error with create texture: " << SDL_GetError() << std::endl;
			}
			const std::string& message()const{
				return _message;
			}

			SDL_Rect rect;
		private:
			std::string _message;
			
		};

		class Input{
		public:const std::string& message()const{
					return _message;
				}

					   SDL_Rect rect;
		private:
			std::string _message;
		};
	}
}