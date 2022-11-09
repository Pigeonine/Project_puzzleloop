#include "Texture.h"

static GLuint textureID;
GLubyte* textureData;
int imageWidth, imageHeight;

#define WINDOW_X 200
#define WINDOW_Y 200

#define WINDOW_WIDTH 1280		// window's width
#define WINDOW_HEIGHT 720		// window's height

#define boundaryX (WINDOW_WIDTH)/2
#define boundaryY (WINDOW_HEIGHT)/2

FIBITMAP* Texture::createBitMap() {
	FREE_IMAGE_FORMAT format = FreeImage_GetFileType(image_name, 0);
	if (format == -1) {
		cout << "Could not find image: " << image_name << " - Aborting." << endl;
		exit(-1);
	}
	else if (format == FIF_UNKNOWN) {
		cout << "Couldn't determine file format - attempting to get from file extension..." << endl;
		format = FreeImage_GetFIFFromFilename(image_name);

		if (!FreeImage_FIFSupportsReading(format)) {
			cout << "Detected image format cannot be read!" << endl;
			exit(-1);
		}
	}

	FIBITMAP* bitmap = FreeImage_Load(format, image_name);
	int bitsPerPixel = FreeImage_GetBPP(bitmap);
	FIBITMAP* bitmap32;
	if (bitsPerPixel == 32) {
		cout << "Source image has " << bitsPerPixel << " bits per pixel. skipping conversion." << endl;
		bitmap32 = bitmap;
	}
	else {
		cout << "Source image has " << bitsPerPixel << " bits per pixel. Converting to 32-bit colour." << endl;
		bitmap32 = FreeImage_ConvertTo32Bits(bitmap);
	}
	return bitmap32;
}

void Texture::generateTexture() {
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imageWidth, imageHeight, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, textureData);
}

void Texture:: initTexture() {
	FIBITMAP* bitmap32 = createBitMap();
	imageWidth = FreeImage_GetWidth(bitmap32);
	imageHeight = FreeImage_GetHeight(bitmap32);
	textureData = FreeImage_GetBits(bitmap32);

	generateTexture();
}

void Texture::displayCharacters()
{
	glRasterPos2f(text_x, text_y);
	for (int i = 0; i < text.size(); i++)
		glutBitmapCharacter(font, text[i]);
}

void Texture::setText(string txt)
{
	text = txt;
}

void Texture::setTextLoc(float x, float y)
{
	text_x = x; text_y = y;
}

void Texture::setTextFont(void* fnt)
{
	font = fnt;
}

Texture::Texture()
{
}

void Texture::setImageName(char const* picname)
{
	image_name = picname;
}


string Texture::getImageName()
{
	return image_name;
}

void Texture::drawSquareWithTexture()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex2f(-WINDOW_WIDTH / 4.0f,-WINDOW_HEIGHT / 4.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex2f(-WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex2f(WINDOW_WIDTH / 4.0f, WINDOW_HEIGHT / 4.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex2f(WINDOW_WIDTH / 4.0f, -WINDOW_HEIGHT / 4.0f);
	glEnd();

	glDisable(GL_TEXTURE_2D);
}
