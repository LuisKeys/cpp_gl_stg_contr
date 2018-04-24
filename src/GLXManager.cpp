#include <iostream>
#include "GLXManager.h"

int GetY(int width, int height, int x) {
	float ratio = (float) height / (float) width;
	float calcY = (float) x * ratio;
	return (int) calcY;
}

void Transform(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, GLX_VP_WIDTH, GetY(width, height, GLX_VP_WIDTH), 0, -1, 1);
}

void GLXManager::Init(GLXState * state, int * argcp, char** argv) {  
  GLXColor color;

  state->argcp = argcp;
  state->argv = argv;
  state->width = 500;
  state->height = 500;
  state->left = 0;
  state->top = 0;
  state->mode = GLX_FULL_SCREEN;
  color.GetColorByName(GLXCOLOR_LIGHT_YELLOW, &state->backColor);

  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(state->width, state->height);
  glutInitWindowPosition(state->left, state->top);
  glutCreateWindow(state->windowName);

  if(state->mode == GLX_FULL_SCREEN)
	glutFullScreen();
}

void GLXManager::Loop(void (*displayFunction)(void)) {
	glutDisplayFunc(displayFunction);
	glutReshapeFunc(Transform);
	glutMainLoop();
}

void GLXManager::Clear(GLXState * state) {
  glClearColor(state->backColor.red, state->backColor.green, state->backColor.blue, state->backColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

void GLXManager::Update() {
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

