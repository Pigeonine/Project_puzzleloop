#include "Material.h"

Material::Material()
{
	emission[0] = 0.0f; emission[1] = 0.0f; emission[2] = 0.0f; emission[3] = 0.0f;
	ambient[0] = 0.0f; ambient[1] = 0.0f; ambient[2] = 0.0f; ambient[3] = 0.0f;
	diffuse[0] = 0.0f; diffuse[1] = 0.0f; diffuse[2] = 0.0f; diffuse[3] = 0.0f;
	specular[0] = 0.0f; specular[1] = 0.0f; specular[2] = 0.0f; specular[3] = 0.0f;
	shininess[0] = 0.0f;
}

void Material::setEmission(float r, float g, float b, float a)
{
	emission[0] = r; emission[1] = g; emission[2] = b; emission[3] = a;
}

void Material::setAmbient(float r, float g, float b, float a)
{
	ambient[0] = r; ambient[1] = b; ambient[2] = b; ambient[3] = a;
}

void Material::setDiffuse(float r, float g, float b, float a)
{
	diffuse[0] = r; diffuse[1] = g; diffuse[2] = b; diffuse[3] = a;
}

void Material::setSpecular(float r, float g, float b, float a)
{
	specular[0] = r; specular[1] = g; specular[2] = b; specular[3] = a;
}

void Material::setShininess(float sh)
{
	shininess[0] = sh;
}
