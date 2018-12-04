#include "texture.h"
#include <stdexcept>

SGTexture::SGTexture(const char* path, WrappingType sType, WrappingType tType, FiltrationType minFilter, FiltrationType magFilter)
{
	if (magFilter == NearestMipmapNearest ||
		magFilter == LinearMipmapNearest ||
		magFilter == NearestMipmapLinear)
		throw std::exception("Error: texture initialization failed. Cannot use mipmap filter as magnification filter!");

	borderColor = new float[4];
	for (int i = 0; i < 4; i++)
	{
		borderColor[i] = 1.0f;
	}

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	if (sType == ClampToBorder || tType == ClampToBorder)
	{
		glTextureParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, sType);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, tType);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

	image = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	SOIL_free_image_data(image);

	glBindTexture(GL_TEXTURE_2D, 0);
}
SGTexture::~SGTexture()
{
	delete[] borderColor;
}
void SGTexture::setSWrapping(WrappingType type)
{
	glBindTexture(GL_TEXTURE_2D, textureID);
	if (type == ClampToBorder)
	{
		glTextureParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, type);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void SGTexture::setTWrapping(WrappingType type)
{
	glBindTexture(GL_TEXTURE_2D, textureID);
	if (type == ClampToBorder)
	{
		glTextureParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, type);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void SGTexture::setBorderColor(float r, float g, float b, float a)
{
	borderColor[0] = r;
	borderColor[1] = g;
	borderColor[2] = b;
	borderColor[3] = a;
}
void SGTexture::setMinFiltration(FiltrationType type)
{
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, type);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void SGTexture::setMagFiltration(FiltrationType type)
{
	if (type == NearestMipmapNearest ||
		type == LinearMipmapNearest ||
		type == NearestMipmapLinear)
		throw std::exception("Error: texture initialization failed. Cannot use mipmap filter as magnification filter!");
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, type);
	glBindTexture(GL_TEXTURE_2D, 0);
}
void SGTexture::setTextureAsCurrent()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}
void SGTexture::resetCurrentTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}