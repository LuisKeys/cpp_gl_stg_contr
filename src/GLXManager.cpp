#include <iostream>
#include "GLXManager.h"
#include <chrono>
#include <unistd.h>

GLXState * _statep;
GLXInput  _input;

void sleep(int milliseconds) {
  usleep(milliseconds * 1000);
}

unsigned long GetTickCount() {
    using namespace std::chrono;
    return duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}

void CalculateFrameRate() {
    static float framesPerSecond    = 0.0f;
    static float lastTime   = 0.0f;
    float currentTime = GetTickCount() * 0.001f;    
    ++framesPerSecond;
    if( currentTime - lastTime > 1.0f ) {
        lastTime = currentTime;
        if(_statep->window.displayFPS == GLX_FPS_ON) {
          std::cout << "Current Frames Per Second:" << (int)framesPerSecond << std::endl; 
        }
        framesPerSecond = 0;
    }
}   

int GetY(int width, int height, int x) {
	float ratio = (float) height / (float) width;
	float calcY = (float) x * ratio;
	return (int) calcY;
}

void Clear() {
  glClearColor(_statep->window.backColor.red, _statep->window.backColor.green, _statep->window.backColor.blue, _statep->window.backColor.alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

void Update() {
  CalculateFrameRate();
  glFlush();
  glutSwapBuffers();
  glutPostRedisplay();
}

void Transform(int width, int height) {
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, GLX_VP_WIDTH, GetY(width, height, GLX_VP_WIDTH), 0, -1, 1);
}

void RenderFunction() {
    _input.GetMousePosition();
    Clear();
    GLXShapes glxShapes;

    GLXColor color;
    color.red = 1.0f;
    glxShapes.Line(&color, 1.0, 0, 0, 100, 100);

    color.red = 0.0f;
    color.green = 1.0f;

    glxShapes.Circle(&color, 1.0, 100, 100, 50, 0, 60);

    Update();
    sleep(100);
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
  statep->window.displayFPS = GLX_FPS_OFF;

  color.GetColorByName(GLXCOLOR_BLACK, &statep->window.backColor);

  glutInit(argcp, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowSize(statep->window.width, statep->window.height);
  glutInitWindowPosition(statep->window.left, statep->window.top);
  glutCreateWindow(statep->window.windowName);

  if(statep->window.mode == GLX_FULL_SCREEN)
	 glutFullScreen();

  SDL_Init (SDL_INIT_EVENTS);
  Loop(RenderFunction);
}

void GLXManager::Loop(void (*displayFunction)(void)) {
 	glutDisplayFunc(displayFunction);
	glutReshapeFunc(Transform);
	glutMainLoop();
}
