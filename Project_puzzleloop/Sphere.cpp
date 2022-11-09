#include "Sphere.h"





Sphere::Sphere(float r, int sl, int st)
{
	radius = r; slice = sl; stack = st;
}

void Sphere::setRadius(float r)
{
	radius = r;
}

float Sphere::getRadius() const
{
	return radius;
}

void Sphere::setSlidce(int sl)
{
	slice = sl;
}

void Sphere::setStack(int st)
{
	stack = st;
}

void Sphere::setCenter(float x, float y, float z)
{
	center[0] = x; center[1] = y; center[2] = z;
}

const float* Sphere::getCenter() const
{
	return center;
}

void Sphere::setVelocity(float x, float y, float z)
{
	velocity[0] = x; velocity[1] = y; velocity[2] = z;
}

const float* Sphere::getVelocity() const
{
	return velocity;
}

void Sphere::setMTL(const Material& m)
{
	mtl = m;
}

void Sphere::move()
{
	
}

void Sphere::draw() const
{
	glPushMatrix();
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_EMISSION, mtl.emission);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mtl.ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mtl.diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mtl.specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mtl.shininess);
	glTranslatef(center[0], center[1], center[2]);
	glutSolidSphere(radius, slice, stack);
	glPopMatrix();
}
