#pragma once
#include "GL/freeglut.h"
#include "GL/gl.h"
#include "GLXColor.h"

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
};

class GLXManager {
	public:
		const int FULL_SCREEN = 1;
		const int WINDOWED = 0;

		void Init(GLXState state);
};