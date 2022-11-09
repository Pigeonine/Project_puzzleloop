#include <iostream>
#include <vector>
#include <time.h>

#include "Sphere.h"
#include "Light.h"
#include "Texture.h"

using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 1280		// window's width
#define WINDOW_HEIGHT 720		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2


clock_t start_t = clock();
clock_t end_t;



void initialize() {
	
}

void idle() {
	/* Implement: update spheres and handle collision at boundary*/

	end_t = clock();

	if (end_t - start_t > 1000 / 60) {
		
		start_t = end_t;
	}
	glutPostRedisplay();
}

void display() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-boundaryX, boundaryX, -boundaryY, boundaryY, -100.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	/* Implement: Draw 2D (texture, ID and name)*/
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	/* Implement: Draw 3D (light and spheres)*/
	
	

	glutSwapBuffers();
	

	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);

}

int main(int argc, char** argv) {
	// init GLUT and create Window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowPosition(WINDOW_X, WINDOW_Y);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Puzzle Loop");
	initialize();

	// register callbacks
	glutDisplayFunc(display);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
