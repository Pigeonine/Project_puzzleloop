#pragma once
#include <GL/glut.h>

class Light
{
public:
	Light();
	Light(float x, float y, float z, int LID);
	void setLightID(int LID);
	void setPosition(float x, float y, float z, float a);
	void setAmbient(float r, float g, float b, float a);
	void setDiffuse(float r, float g, float b, float a);
	void setSpecular(float r, float g, float b, float a);
	void enableLight(bool bOn);
	void draw() const;
	bool currentLight();
private: 
	int lightID;
	float pos[4];
	float ambient[4];
	float diffuse[4];
	float specular[4];
	bool bLighton;
};


