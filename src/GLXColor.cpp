#include "GLXColor.h"

static void GLXColor::GetColorByName(int colorName, GLXColor * colorp) {	
	switch(colorName) {
		case RED: 
			colorp->red = 1.0f;
			colorp->green = 0.0f;
			colorp->blue = 0.0f;
	}
}