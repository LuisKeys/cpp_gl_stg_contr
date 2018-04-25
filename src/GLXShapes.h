#pragma once

#include "GLXColor.h"
#include <iostream>
#include <cmath>
#include "GL/freeglut.h"
#include "GL/gl.h"

#define PI 3.14159265359

class GLXShapes {
	public:
		void Line(GLXColor * color, float width, int x1, int y1, int x2, int y2);
		void Circle(GLXColor * color, float width, int x, int y, int radius, int startAng, int endAngle);
};