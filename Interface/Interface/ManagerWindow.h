#pragma once
#include "Window.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes of manager*/
	namespace Manager{
		/*Manager to Window class*/
		struct Window{
			/*Getter window flags
			*@param SDL2::Display::Window& window to information
			*@return Uint32 flags*/
			Uint32 static flag(Display::Window&);

			/*Hide window
			*@param SDL2::Display::Window& window to information*/
			void static hide(Display::Window&);

			/*Show window
			*@param SDL2::Display::Window& window to information*/
			void static show(Display::Window&);

			/*Raise window above other windows and set the input focus
			*@param SDL2::Display::Window& window to information*/
			void static raise(Display::Window&);

			/*Make a window as large as possible
			*@param SDL2::Display::Window& window to information*/
			void static maximum(Display::Window&);

			/*Make a window to iconic
			*@param SDL2::Display::Window& window to information*/
			void static minimum(Display::Window&);

			/*Restore window size and possition to manimized or minimized window
			*@param SDL2::Display::Window& window to information*/
			void static  restore(Display::Window&);

			/*Set a window on fullscreen
			*@param SDL2::Display::Window& window to information
			*@param Uint32 SDL_WindowFlag to fullscreen*/
			void static fullscreen(Display::Window&, Uint32 = SDL_WINDOW_FULLSCREEN_DESKTOP);

			/*Fill in information about the display mode used when a fullscreen
			*@param SDL2::Display::Window& window to information
			*@param SDL_DisplayMode* the get information*/
			int static getDisplayMode(Display::Window&, SDL_DisplayMode*);

			/*Set the display mode used then a fullscreen windowis visible
			*@param SDL2::Display::Window& window to information
			*@param const SDL_DisplayMode* mode to use or nullptr fo default mode
			*@return true on succes or false if setting the disply mode failed*/
			bool static setDisplayMode(Display::Window&, const SDL_DisplayMode*);

			/*Set a window's input grab mode
			*@param SDL2::Display::Window& window to information
			*@SDL_bool true to gram input or false to release*/
			void static setGrab(Display::Window&, SDL_bool);

			/*Get a window's input grab mode
			*@param SDL2::Display::Window& window to information
			*@return SDL_bool true if input is grabbed or false otherwise*/
			SDL_bool static getGrab(Display::Window&);
		};
	}
}
