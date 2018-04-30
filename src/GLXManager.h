#pragma once
#include <string>
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GLXControls.h"
#include "GLXColor.h"
#include "GLXShapes.h"
#include "GLXInput.h"


#define GLX_FULL_SCREEN 1
#define GLX_WINDOWED  0

#define GLX_FPS_OFF 0
#define GLX_FPS_ON 1

#define GLX_TRUE 1
#define GLX_FALSE 0

#define GLX_VP_WIDTH 1000

class GLXWindow {
	public:
		int *argcp;
		char **argv;
		int width = 500;
		int height = 500;
		int left = 0; 
		int top = 0;
		int mode = GLX_WINDOWED;
		GLXColor backColor;
		int displayFPS = 0;
		const char * windowName;
};

class GLXState {
	public:
		GLXWindow window;
};

class GLXManager {

	public:
		void Init(GLXState * state, int * argcp, char** argv);
		void Loop(void (*displayFunction)(void));

};