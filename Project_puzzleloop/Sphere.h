#pragma once
#include <GL/glut.h>
#include "Material.h"

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 1280		// window's width
#define WINDOW_HEIGHT 720		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2

class Sphere
{
public:
	Sphere(float r, int sl, int st);

	void setRadius(float r);
	float getRadius() const;

	void setSlice(int sl);
	void setStack(int st);
	void setCenter(float x, float y, float z);
	const  float* getCenter() const;
	void setVelocity(float x, float y, float z);
	const float* getVelocity() const;

	void setMTL(const Material& m);

	void move();
	void draw() const;

private:
	float radius;
	int slice;
	int stack;
	float center[3];
	float velocity[3];
	Material mtl;
};

