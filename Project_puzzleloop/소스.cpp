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

Material red; // °ø »ö±ò Ãß°¡(11/9)
Material green;
Material blue;



clock_t start_t = clock();
clock_t end_t;

Light light(boundaryX, boundaryY, boundaryX / 2, GL_LIGHT0);//ºû Ãß°¡(11/9)


void initialize() {
	light.setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
	light.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	light.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);

	
	red.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	red.setAmbient(0.8f, 0.1f, 0.1f, 1.0f);
	red.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	red.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	red.setShininess(10.0f);

	green.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	green.setAmbient(0.1f, 0.8f, 0.1f, 1.0f);
	green.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	green.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	green.setShininess(10.0f);

	blue.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	blue.setAmbient(0.1f, 0.1f, 0.8f, 1.0f);
	blue.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	blue.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	blue.setShininess(10.0f);
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


	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	

	light.draw();

	
	

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
