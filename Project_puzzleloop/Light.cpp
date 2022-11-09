#include "Light.h"

Light::Light()
{
	lightID = GL_LIGHT0;
	pos[0] = 0.0f; pos[1] = 0.0f; pos[2] = 0.0f; pos[3] = 1.0f;
	ambient[0] = 0.0f; ambient[1] = 0.0f; ambient[2] = 0.0f; ambient[3] = 0.0f;
	diffuse[0] = 0.0f; diffuse[1] = 0.0f; diffuse[2] = 0.0f; diffuse[3] = 0.0f;
	specular[0] = 0.0f; specular[1] = 0.0f; specular[2] = 0.0f; specular[3] = 0.0f;
	bLighton = true;
}

Light::Light(float x, float y, float z, int LID)
{
	lightID = LID;
	pos[0] = x; pos[1] = y; pos[2] = z; pos[3] = 1.0f;
	ambient[0] = 0.0f; ambient[1] = 0.0f; ambient[2] = 0.0f; ambient[3] = 0.0f;
	diffuse[0] = 0.0f; diffuse[1] = 0.0f; diffuse[2] = 0.0f; diffuse[3] = 0.0f;
	specular[0] = 0.0f; specular[1] = 0.0f; specular[2] = 0.0f; specular[3] = 0.0f;
	bLighton = true;
}

void Light::setLightID(int LID)
{
	lightID = LID;
}

void Light::setPosition(float x, float y, float z, float a=1.0f)
{
	pos[0] = x; pos[1] = y; pos[2] = z; pos[3] = a;
}

void Light::setAmbient(float r, float g, float b, float a)
{
	ambient[0] = r; ambient[1] = g; ambient[2] = b; ambient[3] = a;
}

void Light::setDiffuse(float r, float g, float b, float a)
{
	diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}

void Light::setSpecular(float r, float g, float b, float a)
{
	specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}

void Light::enableLight(bool bOn)
{
	bLighton = bOn;
}

void Light::draw() const
{
	glLightfv(lightID, GL_AMBIENT, ambient);
	glLightfv(lightID, GL_DIFFUSE, diffuse);
	glLightfv(lightID, GL_SPECULAR, specular);
	glLightfv(lightID, GL_POSITION, pos);
	
}

bool Light::currentLight()
{
	return bLighton;
}
