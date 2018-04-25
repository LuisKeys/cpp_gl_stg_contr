#include <iostream>
#include "GLXManager.h"
#include <chrono>

GLXState * _statep;

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

void GLXManager::Init(GLXState * statep, int * argcp, char** argv) {  
  GLXColor color;

  _statep = statep;

  statep->window.argcp = argcp;
  statep->window.argv = argv;
  statep->window.width = 500;
  statep->window.height = 500;
  statep->window.left = 0;
  statep->window.top = 0;
  statep->window.mode = GLX_WINDOWED;
  statep->window.windowName = "GLX Window";
  statep->window.displayFPS = GLX_FPS_ON;

  color.GetColorByName(GLXCOLOR_BLACK, &statep->window.backColor);

  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(statep->window.width, statep->window.height);
  glutInitWindowPosition(statep->window.left, statep->window.top);
  glutCreateWindow(statep->window.windowName);

  if(statep->window.mode == GLX_FULL_SCREEN)
	glutFullScreen();
}

void GLXManager::Loop(void (*displayFunction)(void)) {
	glutDisplayFunc(displayFunction);
	glutReshapeFunc(Transform);
	glutMainLoop();
}

void GLXManager::Clear() {
  glClearColor(_statep->window.backColor.red, _statep->window.backColor.green, _statep->window.backColor.blue, _statep->window.backColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

void GLXManager::Update() {
  CalculateFrameRate();
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void GLXManager::CalculateFrameRate() {
    static float framesPerSecond    = 0.0f;
    static float lastTime   = 0.0f;
    float currentTime = GetTickCount() * 0.001f;    
    ++framesPerSecond;
    if( currentTime - lastTime > 1.0f )
    {
        lastTime = currentTime;
        if(_statep->window.displayFPS == GLX_FPS_ON) {
          std::cout << "Current Frames Per Second:" << (int)framesPerSecond << std::endl; 
        }
        framesPerSecond = 0;
    }
}   

unsigned long GLXManager::GetTickCount() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

