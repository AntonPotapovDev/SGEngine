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