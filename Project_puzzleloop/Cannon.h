#pragma once
#include <random>
#include <iostream>
#include "Sphere.h"

extern Material red;
extern Material green;
extern Material blue;
extern float Radius;

enum colors {RED, GREEN, BLUE};

class Cannon {
public:
	void initialize();

	void cannon_move();

	void sphere_move();

	void draw() const;

	
private:
	Sphere first_sphere;
	Sphere second_sphere;
	Sphere shooting_sphere;

	bool shooting;

};