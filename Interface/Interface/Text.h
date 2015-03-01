#pragma once
#include <string>
#include <iostream>
#include <memory>
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "SDL_render.h"
#include "Event.h"
/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes to Graphics share and manipulation*/
	namespace Graphic{
		class Text{
		public:
			/*Create text texture with message
			*@param SDL_Renderer renderer to create texture
			*@param std::string path to file ttf
			*@param std::string text to showed
			*@param int size font
			*@param SDL_Color text color*/
			Text(SDL_Renderer* renderer, const std::string &path, const std::string &text, int size, const SDL_Color color)
				:_color(color), _surface(nullptr), _texture(nullptr), _message(text){
				if (!(_font = TTF_OpenFont(path.c_str(), size)))
					std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
				else
					if (!(_surface = TTF_RenderText_Solid(_font, text.c_str(), _color)))
						std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
					else
						if (!(_texture = SDL_CreateTextureFromSurface(renderer, _surface)))
							std::cout << "Error with create texture: " << SDL_GetError() << std::endl;
			}

			/*Create text texture with message
			*@param TTF_Font style font
			*@param SDL_Renderer renderer to create texture
			*@param std::string text to showed
			*@param int size font
			*@param SDL_Color text color*/
			Text(TTF_Font* font, SDL_Renderer* renderer, const std::string& text, const SDL_Color color)
				:_color(color), _surface(nullptr), _texture(nullptr), _message(text){
				if (!(_surface = TTF_RenderText_Solid(_font, text.c_str(), _color)))
					std::cout << "Error with load TTF: " << TTF_GetError() << std::endl;
				else
					if (!(_texture = SDL_CreateTextureFromSurface(renderer, _surface)))
						std::cout << "Error with create texture: " << SDL_GetError() << std::endl;
			}

			~Text(){
				SDL_DestroyTexture(_texture);
				SDL_FreeSurface(_surface);
				TTF_CloseFont(_font);
			}

			/*SDL_Texture getter
			*@return SDL_Texture*/
			SDL_Texture* texture()const{
				return _texture;
			}

			/*Set new from keyboard
			*@param SDL_Renderer renderer to clear, copy and present on screen
			*@param SDL2::Graphic::Sprite array to show under text
			*@param uint32 size to array*/
			bool input(SDL_Renderer* renderer, SDL2::Graphic::Sprite sprites[], uint32_t size){
				bool success = false;
				bool quit = false;
				SDL2::Events::Event ev;
				SDL_StartTextInput();
				std::string last = _message;
				while (!quit){
					if (ev.poll()){
						SDL_RenderClear(renderer);

						if (ev.key() == SDLK_BACKSPACE && _message.length())
							_message.pop_back();
						else if (ev.key() == SDLK_ESCAPE){
							_message = last;
							quit = true;
						}
						else if (ev.key() == SDLK_RETURN)
							quit = true;
						else if (ev.type() == SDL_TEXTINPUT)
							_message += ev.get().text.text;

						refresh(renderer);
						for (auto i = 0; i < size; ++i)
							SDL_RenderCopy(renderer, sprites[i].source()._Get()->texture(), &sprites[i].rectSource, &sprites[i].rectShowed);
						SDL_RenderCopy(renderer, _texture, nullptr, &rect);
						SDL_RenderPresent(renderer);
					}
				}
				SDL_StopTextInput();
				return success;
			}

			SDL_Rect rect;
		protected:
			TTF_Font* _font;
			SDL_Surface* _surface;
			SDL_Texture* _texture;
			SDL_Color _color;

			std::string _message;

		private:
			bool refresh(SDL_Renderer* renderer){
				SDL_DestroyTexture(_texture);
				SDL_FreeSurface(_surface);

				_surface = TTF_RenderText_Solid(_font, _message.c_str(), _color);
				_texture = SDL_CreateTextureFromSurface(renderer, _surface);

				return (_texture && _surface) ? true : false;
			}
		};
	}
}