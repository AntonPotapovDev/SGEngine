#ifndef TEXTURE_H
#define TEXTURE_H

#include "context/glew.h"
#include "SOIL/SOIL.h"

// Enum of texture wrapping types
enum WrappingType
{
	Repeat,
	MirroredRepeat,
	ClampToEdge,
	ClampToBorder
};

// Enum of types of texture filters
enum FiltrationType
{
	Nearest,
	Linear,
	NearsetMipmapNearest,
	LinearMipmapNearest,
	NearestMipmapLinear
};

/*
    This class represents a texture object, 
	which can be used to draw models using openGL
*/
class SGTexture
{
public:
	// Constructor: creates texture from raster image
	// and sets wrapping and filtration options
	SGTexture
	(
		const char* path,           // Path to image
		WrappingType sType,         // Texture wrapping type for axis 'S' ('X')
		WrappingType tType,         // Texture wrapping type for axis 'T' ('Y')
		FiltrationType minFilter,   // Type of minifying texture filter 
		FiltrationType magFilter    // Type of magnifying texture filter
	);

	// Destructor: frees up texture resources
	~SGTexture();

	// Setter: sets texture wrapping type for axis 'S' ('X')
	void setSWrapping
	(
		WrappingType type
	);

	// Setter: sets texture wrapping type for axis 'T' ('Y')
	void setTWrapping
	(
		WrappingType type
	);

	// Setter: sets type of minifying texture filter 
	void setMinFiltration
	(
		FiltrationType type
	);

	// Setter: sets type of magnifying texture filter
	void setMagFiltration
	(
		FiltrationType type
	);

	// Setter: activates this texture, 
	// openGL will use this texture for next drawing operations 
	// (if current shader program can get 'sampler2D' as a uniform)
	void setTextureAsCurrent();

private:
	unsigned char* image;  // Path to image
	GLuint textureID;      // openGL ID of texture object
	float* borderColor;    // Color of borders, which is seted when using 'ClampToBorder' type of wrapping
	int width;             // Width of image
	int height;            // Height of image
};

#endif

