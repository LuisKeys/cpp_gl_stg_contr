#include <iostream>
#include "GLXManager.h"

GLXState _glxState;
GLXManager _glxManager;
GLXShapes _glxShapes;

int main(int argc, char** argv)
{
  _glxManager.Init(&_glxState, &argc, argv);

  return 0;
}
