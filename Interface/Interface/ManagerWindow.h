#pragma once
#include "Window.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes of manager*/
	namespace Manager{
		/*Manager to Window class*/
		struct Window{
			/*Getter window flags
			*@param const SDL2::Display::Window& window to information
			*@return Uint32 flags*/
			Uint32 static inline flag(const Display::Window& window){
				return SDL_GetWindowFlags(window.get());
			}

			/*Hide window
			*@param SDL2::Display::Window& window to information*/
			void static inline hide(const Display::Window& window){
				SDL_HideWindow(window.get());
			}

			/*Show window
			*@param const SDL2::Display::Window& window to information*/
			void static inline show(const Display::Window& window){
				SDL_ShowWindow(window.get());
			}

			/*Raise window above other windows and set the input focus
			*@param const SDL2::Display::Window& window to information*/
			void static inline raise(const Display::Window& window){
				SDL_RaiseWindow(window.get());
			}

			/*Make a window as large as possible
			*@param const SDL2::Display::Window& window to information*/
			void static inline maximum(const Display::Window& window){
				SDL_MaximizeWindow(window.get());
			}

			/*Make a window to iconic
			*@param const SDL2::Display::Window& window to information*/
			void static inline minimum(const Display::Window& window){
				SDL_MinimizeWindow(window.get());
			}

			/*Restore window size and possition to manimized or minimized window
			*@param const SDL2::Display::Window& window to information*/
			void static inline restore(const Display::Window& window){
				SDL_RestoreWindow(window.get());
			}

			/*Set a window on fullscreen
			*@param const SDL2::Display::Window& window to information
			*@param Uint32 SDL_WindowFlag to fullscreen*/
			void static inline fullscreen(const Display::Window& window, Uint32 flag){
				SDL_SetWindowFullscreen(window.get(), flag);
			}

			/*Fill in information about the display mode used when a fullscreen
			*@param const SDL2::Display::Window& window to information
			*@param SDL_DisplayMode* the get information*/
			int static inline getDisplayMode(const Display::Window& window, SDL_DisplayMode* mode){
				return SDL_GetWindowDisplayMode(window.get(), mode);
			}

			/*Set the display mode used then a fullscreen windowis visible
			*@param const SDL2::Display::Window& window to information
			*@param const SDL_DisplayMode* mode to use or nullptr fo default mode
			*@return true on succes or false if setting the disply mode failed*/
			bool static inline setDisplayMode(const Display::Window& window, const SDL_DisplayMode* mode){
				return !SDL_SetWindowDisplayMode(window.get(), mode);
			}

			/*Set a window's input grab mode
			*@param const SDL2::Display::Window& window to information
			*@SDL_bool true to gram input or false to release*/
			void static inline setGrab(const Display::Window& window, SDL_bool grabbed){
				SDL_SetWindowGrab(window.get(), grabbed);
			}

			/*Get a window's input grab mode
			*@param const SDL2::Display::Window& window to information
			*@return SDL_bool true if input is grabbed or false otherwise*/
			SDL_bool static getGrab(const Display::Window& window){
				return SDL_GetWindowGrab(window.get());
			}
		};
	}
}
