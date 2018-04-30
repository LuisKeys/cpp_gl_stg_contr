#pragma once
#include <iostream>
#include "SDL2/SDL.h"

#define GLX_MOUSE_EVENT 1
#define GLX_KEYBOARD_EVENT 2

class GLXInput {
	public:
		int type;
		int x;
		int y;
		int value;
		SDL_Event e;
		void GetMousePosition();
};