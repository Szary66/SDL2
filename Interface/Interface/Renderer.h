#pragma once
#include <memory>
#include "SDL_render.h"
#include "Window.h"

namespace SDL2{
	namespace Display{
		class Renderer{
		public:
			Renderer(const Renderer&) = delete;
			Renderer(Renderer&) = delete;
			Renderer()
				:_renderer(nullptr){}

			bool create(const Window& window, SDL_RendererFlags flag = SDL_RENDERER_ACCELERATED){
				return _renderer = SDL_CreateRenderer(window.get(), 0, flag);
			}

			~Renderer(){
				SDL_RenderClear(_renderer);
			}

			SDL_Renderer* const get()const{
				return _renderer;
			}
		private:
			SDL_Renderer* _renderer;
		};
	}
}