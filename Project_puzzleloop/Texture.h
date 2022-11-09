#pragma once
#include <string>
#include <iostream>
#include <GL/glut.h>
#include <FreeImage.h>
using namespace std;
class Texture
{
public:
	Texture();
	Texture(char * picname) :image_name(picname) {}
	void setImageName(char const* picname);
	string getImageName();
	void drawSquareWithTexture();
	FIBITMAP* createBitMap();
	void generateTexture();
	void initTexture();

	void displayCharacters();
	void setText(string txt);
	void setTextLoc(float x, float y);
	void setTextFont(void* fnt);


private:
	char const *image_name;

	void* font;
	string text;
	float text_x;
	float text_y;
};

