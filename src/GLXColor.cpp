#include "GLXColor.h"

void GLXColor::GetColorByName(int colorName, GLXColor * colorp) {	
	switch(colorName) {
		case GLXCOLOR_RED: 
			colorp->red = 1.0f;
			colorp->green = 0.0f;
			colorp->blue = 0.0f;
			break;

		case GLXCOLOR_GREEN: 
			colorp->red = 0.0f;
			colorp->green = 1.0f;
			colorp->blue = 0.0f;
			break;
			
		case GLXCOLOR_BLUE: 
			colorp->red = 0.0f;
			colorp->green = 0.0f;
			colorp->blue = 1.0f;
			break;
			
		case GLXCOLOR_LIGHT_YELLOW: 
			colorp->red = 1.0f;
			colorp->green = 1.0f;
			colorp->blue = 0.5f;
			break;
	}
}