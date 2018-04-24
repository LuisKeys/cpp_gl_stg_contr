#pragma once

#define GLXCOLOR_RED 1
#define GLXCOLOR_GREEN 2
#define GLXCOLOR_BLUE 3
#define GLXCOLOR_LIGHT_YELLOW 4

class GLXColor {
	public:
		float red = 0.0f;
		float green = 0.0f;
		float blue = 0.0f;
		float alpha = 0.0f;
	void GetColorByName(int colorName, GLXColor * colorp);
};