#include <iostream>
#include "GLXManager.h"

GLXState glxState;
GLXManager glxManager;

void renderFunction()
{

  glxState.windowName = "GLX Window";
  glxManager.Clear(&glxState);

  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_POLYGON);
    glVertex2f(0.0, 0.0);
    glVertex2f(0.0, 500.0);
    glVertex2f(500.0, 500.0);
    glVertex2f(500.0, 0.0);
  glEnd();

  glxManager.Update();
}

int main(int argc, char** argv)
{

  glxManager.Init(&glxState, &argc, argv);

  glxManager.Loop(renderFunction);
  return 0;
}
