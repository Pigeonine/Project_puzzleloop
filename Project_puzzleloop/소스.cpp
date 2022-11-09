#include <iostream>
#include <vector>
#include <time.h>

#include "Sphere.h"
#include "Light.h"
#include "Texture.h"
#include "Cannon.h"
using namespace std;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 1280		// window's width
#define WINDOW_HEIGHT 720		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2

Material red; // 공 색깔 추가(11/9)
Material green;
Material blue;

float Radius = 30.0f;

clock_t start_t = clock();
clock_t end_t;

Cannon cannon;

Light light(boundaryX, boundaryY, boundaryX / 2, GL_LIGHT0);//빛 추가(11/9)



void initialize() {
	light.setAmbient(0.5f, 0.5f, 0.5f, 1.0f);
	light.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	light.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);

	
	red.setEmission(0.1f, 0.1f, 0.1f, 1.0f);
	red.setAmbient(0.6f, 0.0f, 0.0f, 1.0f);
	red.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	red.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	red.setShininess(10.0f);

	green.setEmission(0.1f, 0.6f, 0.1f, 1.0f);
	green.setAmbient(0.0f, 0.6f, 0.0f, 1.0f);
	green.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	green.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	green.setShininess(10.0f);

	blue.setEmission(0.1f, 0.1f, 0.3f, 1.0f);
	blue.setAmbient(0.0f, 0.0f, 0.3f, 1.0f);
	blue.setDiffuse(0.7f, 0.7f, 0.7f, 1.0f);
	blue.setSpecular(1.0f, 1.0f, 1.0f, 1.0f);
	blue.setShininess(10.0f);

	cannon.initialize();
}

void specialKeyDown(int key, int x, int y) {
	/* Implement */
	if (!cannon.Is_CCW() && !cannon.Is_CW()) {//한 방향 계속 누르고 있으면 계속 회전하게 설정
		if (cannon.getangle() >= 0.0f && cannon.getangle() < 90.0f) {
			switch (key) {
			case GLUT_KEY_UP:
				cannon.CCW_able();
				break;
			case GLUT_KEY_DOWN:
				cannon.CW_able();
				break;
			case GLUT_KEY_LEFT:
				cannon.CCW_able();
				break;
			case GLUT_KEY_RIGHT:
				cannon.CW_able();
				break;
			}
		}
		else if (cannon.getangle() >= 90.0f && cannon.getangle() < 180.0f)
		{
			switch (key) {
			case GLUT_KEY_UP:
				cannon.CCW_able();
				break;
			case GLUT_KEY_DOWN:
				cannon.CW_able();
				break;
			case GLUT_KEY_LEFT:
				cannon.CW_able();
				break;
			case GLUT_KEY_RIGHT:
				cannon.CCW_able();
				break;
			}
		}
		else if (cannon.getangle() >= 180.0f && cannon.getangle() < 270.0f)
		{
			switch (key) {
			case GLUT_KEY_UP:
				cannon.CW_able();
				break;
			case GLUT_KEY_DOWN:
				cannon.CCW_able();
				break;
			case GLUT_KEY_LEFT:
				cannon.CW_able();
				break;
			case GLUT_KEY_RIGHT:
				cannon.CCW_able();
				break;
			}
		}
		else if (cannon.getangle() >= 270.0f && cannon.getangle() < 360.0f)
		{
			switch (key) {
			case GLUT_KEY_UP:
				cannon.CW_able();
				break;
			case GLUT_KEY_DOWN:
				cannon.CCW_able();
				break;
			case GLUT_KEY_LEFT:
				cannon.CCW_able();
				break;
			case GLUT_KEY_RIGHT:
				cannon.CW_able();
				break;
			}
		}
	}
}
void specialKeyUp(int key, int x, int y) {
	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN || key == GLUT_KEY_LEFT || key == GLUT_KEY_RIGHT) {
		cannon.CCW_disable();
		cannon.CW_disable();
	}

}

void keyboardDown(unsigned char key, int x, int y) {
	if (key == ' ' && !cannon.Is_shooting())
	{
		cannon.toogle_shooting();
	}
}

void idle() {
	end_t = clock();

	if (end_t - start_t > 1000 / 60) {
		if (cannon.Is_CW())
			cannon.CW_tick();
		if (cannon.Is_CCW())
			cannon.CCW_tick();
		cannon.sphere_move();
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
	cannon.draw();
	
	

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
	glutSpecialFunc(specialKeyDown);
	glutSpecialUpFunc(specialKeyUp);
	glutKeyboardFunc(keyboardDown);
	glutIdleFunc(idle);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 0;
}
