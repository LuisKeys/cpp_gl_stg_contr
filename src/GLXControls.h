#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "GLXColor.h"

#define GLX_VISIBLE_ON 1
#define GLX_VISIBLE_OFF 0

class GLXControl {
	public:
		int left = 0;
		int top = 0;
		int width = 50;
		int heigh = 50;
		GLXColor backColor;
		GLXColor foreColor;
		std::string name;
		int visible = GLX_VISIBLE_ON;
};

class GLKnob:GLXControl {
};

class GLXControls {
	public:
		std::vector< GLXControl > controls;
		void Add(GLXControl control);
	private:
};