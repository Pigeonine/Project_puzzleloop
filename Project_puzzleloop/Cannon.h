#pragma once
#include <random>
#include <iostream>
#include "Sphere.h"

#define WINDOW_WIDTH 1280		// window's width
#define WINDOW_HEIGHT 720		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2

extern Material red;
extern Material green;
extern Material blue;
extern float Radius;


class Cannon {
public:
	Cannon();
	void initialize();

	void sphere_move();

	void CW_able();

	void CCW_able();

	void CW_disable();

	void CCW_disable();

	void CW_tick();

	void CCW_tick();

	void set_tick_sensitivity(float sense);

	bool Is_CW() const;

	bool Is_CCW() const;


	bool Is_shooting() const;

	void toogle_shooting();


	void draw() const;

	float getangle();

	
private:
	Sphere first_sphere;
	Sphere second_sphere;
	Sphere shooting_sphere;

	bool CW_rotating;
	bool CCW_rotating;
	bool shooting;
	float angle;
	float tick;
	float distance;
	float velocity;

};