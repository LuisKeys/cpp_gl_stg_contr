#pragma once

class GLXColor {
	public:
		static const int GLXCOLOR_RED = 1;
		static const int GLXCOLOR_GREEN = 2;
		static const int GLXCOLOR_BLUE = 3;

		float red = 0.0f;
		float green = 0.0f;
		float blue = 0.0f;
		float alpha = 0.0f;
	static void GetColorByName(int colorName, GLXColor * colorp);
};