#include "GLXShapes.h"

void GLXShapes::Line(GLXColor * color, float width, int x1, int y1, int x2, int y2) {
  glColor3f(color->red, color->green, color->blue);

	glLineWidth(width); 
	glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
	glEnd();
}

void GLXShapes::Circle(GLXColor * color, float width, int x, int y, int radius, int startAng, int endAngle) {

	if(startAng > endAngle) { 
		std::cout << "Start angle is greater than end angle" << std::endl;
		return;
	}
  
	if(width < 0.0) { 
		width = 1.0;
	}

	if(radius < 0) { 
		radius = 0;
	}

  glColor3f(color->red, color->green, color->blue);
	glLineWidth(width); 

	glBegin(GL_LINES);
		for(int i = startAng; i <= endAngle - 2; i++){
			float angle = 2 * PI * (float)i / 360.0;
			float caclX = std::cos(angle) * (float)radius + x;
			float calcY = std::sin(angle) * (float)radius + y;
			glVertex2f(caclX, calcY);
			angle = 2 * PI * (float)(i + 2) / 360.0;
			caclX = std::cos(angle) * (float)radius + x;
			calcY = std::sin(angle) * (float)radius + y;
			glVertex2f(caclX, calcY);
		}
	glEnd();  
}