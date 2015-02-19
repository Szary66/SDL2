#pragma once
#include <string>
#include <iostream>
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "Renderer.h"
/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to Graphics share and manipulation*/
	namespace Graphic{
		class Text{
		public:
			Text(const SDL2::Display::Renderer& renderer, const std::string &path, const std::string &text, int size, const SDL_Color color)
				:_color(color), _surface(nullptr), _texture(nullptr), _message(text){
				if(!(_font = TTF_OpenFont(path.c_str(), size)))
					std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
				else
					if(!(_surface = TTF_RenderText_Solid(_font, text.c_str(), _color)))
						std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
					else
						if(!(_texture = SDL_CreateTextureFromSurface(renderer.get(), _surface)))
							std::cout << "Error with create texture: " << SDL_GetError() << std::endl;
			}

			Text(TTF_Font* font, const SDL2::Display::Renderer& renderer, const std::string& text, const SDL_Color color)
				:_color(color), _surface(nullptr), _texture(nullptr), _message(text){
				if(!(_surface = TTF_RenderText_Solid(_font, text.c_str(), _color)))
					std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
				else
					if(!(_texture = SDL_CreateTextureFromSurface(renderer.get(), _surface)))
						std::cout << "Error with create texture: " << SDL_GetError() << std::endl;
			}

			~Text(){
				SDL_DestroyTexture(_texture);
				SDL_FreeSurface(_surface);
				TTF_CloseFont(_font);
			}

			SDL_Texture* texture()const{
				return _texture;
			}

			bool input(SDL2::Display::Renderer& renderer){
				bool success = false;
				bool quit = false;
				SDL_Event* ev = new SDL_Event;
				SDL_StartTextInput();

				while(!quit){
					if(SDL_PollEvent(ev)){
						renderer.clear();

						if(ev->key.keysym.sym == SDLK_BACKSPACE && _message.length())
							_message.pop_back();
						else if(ev->key.keysym.sym == SDLK_ESCAPE || ev->key.keysym.sym == SDLK_RETURN)
							quit = true;
						else if(ev->type == SDL_TEXTINPUT)
							_message += ev->text.text;

						success = refresh(renderer);
						//renderer.copy(*this);
						renderer.present();
						SDL_RenderPresent(renderer.get());
					}
				}
				SDL_StopTextInput();
				delete ev;
				return success;
			}

			bool input(const SDL2::Display::Renderer& renderer, SDL_Event* event){
				SDL_StartTextInput();

				if(event->key.keysym.sym == SDLK_BACKSPACE && _message.length())
					_message.pop_back();
				else if(event->key.keysym.sym == SDLK_ESCAPE || event->key.keysym.sym == SDLK_RETURN)
					return false;
				else if(event->type == SDL_TEXTINPUT)
					_message += event->text.text;
				SDL_StopTextInput();
				return refresh(renderer);

			}

			SDL_Rect rect;
		protected:
			TTF_Font* _font;
			SDL_Surface* _surface;
			SDL_Texture* _texture;
			SDL_Color _color;

			std::string _message;

		private:
			bool refresh(const SDL2::Display::Renderer& renderer){
				SDL_DestroyTexture(_texture);
				SDL_FreeSurface(_surface);

				_surface = TTF_RenderText_Solid(_font, _message.c_str(), _color);
				_texture = SDL_CreateTextureFromSurface(renderer.get(), _surface);

				return (_texture && _surface)?true:false;
			}
		};
	}
}