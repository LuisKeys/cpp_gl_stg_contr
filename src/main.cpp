#include <iostream>
#include "GLXManager.h"

GLXState state;

void renderFunction()
{
  glClearColor(state.backColor.red, state.backColor.green, state.backColor.blue, state.backColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 1.0, 1.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
  glEnd();
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

int main(int argc, char** argv)
{
  GLXManager manager;

  state.argcp = &argc;
  state.argv = argv;
  state.width = 500;
  state.height = 500;
  state.left = 0;
  state.top = 0;
  state.mode = manager.FULL_SCREEN;
  GLXColor::GetColorByName(GLXColor::GLXCOLOR_RED, &state.backColor);

  manager.Init(state);

  glutDisplayFunc(renderFunction);

  glutMainLoop();    
  return 0;
}
