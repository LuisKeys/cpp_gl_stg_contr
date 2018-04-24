#pragma once
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GLXColor.h"

#define GLX_FULL_SCREEN 1
#define GLX_WINDOWED  0

#define GLX_VP_WIDTH 1000

class GLXState {
	public:
		int *argcp;
		char **argv;
		int width;
		int height;
		int left; 
		int top;
		int mode;
		GLXColor backColor;
		const char * windowName;
};

class GLXManager {

	public:
		void Init(GLXState * state, int * argcp, char** argv);
		void Loop(void (*displayFunction)(void));
		void Clear(GLXState * state);
		void Update();
};