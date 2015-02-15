#pragma once
#include "Renderer.h"

/*Interfame to SDL2 engine*/
namespace SDL2{
	/*Space with classes of manager*/
	namespace Manager{
		class Renderer{
		public:
			/*Set to renderer blend mode to draw
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param SDL_BlendMode pointer blendMode filled in with the current blend mode
			*@return bool - true if setted or false if not*/
			bool inline backgroundColorMode(SDL2::Display::Renderer &renderer, SDL_BlendMode* blendMode){
				return !SDL_GetRenderDrawBlendMode(renderer.get(), blendMode);
			}

			/*Set color background to draw renderer
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param Uint8* red value used to draw on rendering target
			*@param Uint8* green value used to draw on rendering target
			*@param Uint8* blue value used to draw on rendering target
			*@param Uint8* alpha value used to draw on redering target
			*@return bool true if setted or false if not*/
			bool inline backgroundColor(SDL2::Display::Renderer &renderer, Uint8* r, Uint8* g, Uint8* b, Uint8* a){
				return !SDL_GetRenderDrawColor(renderer.get(), r, g, b, a);
			}

			/*Draw line by coordinates from point to point
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param int x to first coordinate
			*@param int y to first coordinate
			*@param int x to second coordinate
			*@param int y to second coordinate
			*@return bool true if drawed or false if not*/
			bool inline line(SDL2::Display::Renderer& renderer, int x1, int y1, int x2, int y2){
				return !SDL_RenderDrawLine(renderer.get(), x1, y1, x2, y2);
			}

			/*Draw lines by points
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Point pointer with points draw lines by them
			*@param int count lines
			*@return true if drawed or false if not*/
			bool inline lines(SDL2::Display::Renderer& renderer, const SDL_Point* points, int count){
				return !SDL_RenderDrawLines(renderer.get(), points, count);
			}

			/*Draw point by coordinates
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param int x point
			*@param int y point
			*@return true if drawed or false if not*/
			bool inline point(SDL2::Display::Renderer& renderer, int x, int y){
				return !SDL_RenderDrawPoint(renderer.get(), x, y);
			}

			/*Draw points by point 
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param SDL_Point pointer with points to draw
			*@param int count points
			*@return true if drawed or false if not*/
			bool inline points(SDL2::Display::Renderer& renderer, const SDL_Point* points, int count){
				return !SDL_RenderDrawPoints(renderer.get(), points, count);
			}

			/*Draw rectangle by left up point and size it
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Rect pointer
			*@return true if drawed or false if not*/
			bool inline rect(SDL2::Display::Renderer& renderer, const SDL_Rect* rect){
				return !SDL_RenderDrawRect(renderer.get(), rect);
			}


			/*Draw rectangles by left up point and size it
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Rect pointer
			*@param int count rectagles
			*@return true if drawed or false if not*/
			bool inline rects(SDL2::Display::Renderer& renderer, const SDL_Rect* rects, int count){
				return !SDL_RenderDrawRects(renderer.get(), rects, count);
			}

			/*Draw fill rectangle by left up point and size it
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Rect pointer
			*@return true if drawed or false if not*/
			bool inline fillRect(SDL2::Display::Renderer& renderer, const SDL_Rect* rect){
				return !SDL_RenderFillRect(renderer.get(), rect);
			}

			/*Draw fill rectangles by left up point and size it
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Rect pointer
			*@param int count rectangles
			*@return true if drawed or false if not*/
			bool inline fillRect(SDL2::Display::Renderer& renderer, const SDL_Rect* rects, int count){
				return !SDL_RenderFillRects(renderer.get(), rects, count);
			}

			/*Get the drawing area for the current target
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param SDL_Rect pointer*/
			void inline getViewport(SDL2::Display::Renderer& renderer, SDL_Rect* rect){
				SDL_RenderGetViewport(renderer.get(), rect);
			}

			/*Set the drawing area for rendering on the current target
			*@param SDL2::Diplay::Renderer renference renderer to set
			*@param const SDL_Rect pointer*/
			void inline setViewport(SDL2::Display::Renderer& renderer, const SDL_Rect* rect){
				SDL_RenderSetViewport(renderer.get(), rect);
			}
		};
	}
}