#include "GLXInput.h"

void GLXInput::GetMousePosition() {
	SDL_PollEvent(&e);
	std::cout << e.button.button << std::endl;	
}


