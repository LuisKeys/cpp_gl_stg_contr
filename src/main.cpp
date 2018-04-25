#include <iostream>
#include "GLXManager.h"

GLXState _glxState;
GLXManager _glxManager;
GLXShapes _glxShapes;
int _angle = 0;

void renderFunction()
{

  _glxManager.Clear();

  GLXColor color;
  color.red = 1.0f;
  _glxShapes.Line(&color, 1.0, 0, 0, 100, 100);

  color.red = 0.0f;
  color.green = 1.0f;
  _angle += 0;
  if(_angle > 300)
    _angle = 0;
  _glxShapes.Circle(&color, 1.0, 100, 100, 50, _angle, _angle + 60);

  _glxManager.Update();
}

int main(int argc, char** argv)
{

  _glxManager.Init(&_glxState, &argc, argv);

  _glxManager.Loop(renderFunction);
  return 0;
}
