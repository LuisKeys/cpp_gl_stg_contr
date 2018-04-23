#include <iostream>
#include "GLXManager.h"

void GLXManager::Init(GLXState state) {  
  glutInit(state.argcp, state.argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(state.width, state.height);
  glutInitWindowPosition(state.left, state.top);
  glutCreateWindow("OpenGL - First window demo");
  if(state.mode == FULL_SCREEN)
  glutFullScreen();
}
