#include "SDL.h"

struct Color {
	Color(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 0) {
		_color = {red, green, blue, alpha};
	}
	void set(uint8_t red = 0, uint8_t green = 0, uint8_t blue = 0, uint8_t alpha = 0) {
		_color = {red, green, blue, alpha};
	}
	SDL_Color get()const {
		return _color;
	}
private:
	SDL_Color _color;
};