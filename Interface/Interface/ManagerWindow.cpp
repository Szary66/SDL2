//#include "Window.h"
#include "ManagerWindow.h"


namespace SDL2{
	namespace Manager{
		Uint32  Window::flag(Display::Window& window){
			return SDL_GetWindowFlags(window.get());
		}

		void Window::hide(Display::Window& window){
			SDL_HideWindow(window.get());
		}

		void Window::show(Display::Window& window){
			SDL_ShowWindow(window.get());
		}

		void Window::raise(Display::Window& window){
			SDL_RaiseWindow(window.get());
		}

		void Window::maximum(Display::Window& window){
			SDL_MaximizeWindow(window.get());
		}

		void Window::minimum(Display::Window& window){
			SDL_MinimizeWindow(window.get());
		}

		void Window::restore(Display::Window& window){
			SDL_RestoreWindow(window.get());
		}

		void Window::fullscreen(Display::Window& window, Uint32 flag){
			SDL_SetWindowFullscreen(window.get(), flag);
		}

		int Window::getDisplayMode(Display::Window& window, SDL_DisplayMode* mode){
			return SDL_GetWindowDisplayMode(window.get(), mode);
		}

		bool Window::setDisplayMode(Display::Window& window, const SDL_DisplayMode* mode){
			return !SDL_SetWindowDisplayMode(window.get(), mode);
		}

		void Window::setGrab(Display::Window& window, SDL_bool grabbed){
			SDL_SetWindowGrab(window.get(), grabbed);
		}

		SDL_bool Window::getGrab(Display::Window& window){
			return SDL_GetWindowGrab(window.get());
		}
	}
}

