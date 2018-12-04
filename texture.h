#ifndef TEXTURE_H
#define TEXTURE_H

#include "context/glew.h"
#include "SOIL/SOIL.h"

// Enum of texture wrapping types
enum WrappingType
{
	Repeat           = GL_REPEAT,
	MirroredRepeat   = GL_MIRRORED_REPEAT,
	ClampToEdge      = GL_CLAMP_TO_EDGE,
	ClampToBorder    = GL_CLAMP_TO_BORDER
};

// Enum of types of texture filters
enum FiltrationType
{
	Nearest                = GL_NEAREST,
	Linear                 = GL_LINEAR,
	NearestMipmapNearest   = GL_NEAREST_MIPMAP_NEAREST,
	LinearMipmapNearest    = GL_LINEAR_MIPMAP_NEAREST,
	NearestMipmapLinear    = GL_NEAREST_MIPMAP_LINEAR
};

/*
    This class represents a texture object
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

	// Setter: sets the color of borders that are applied 
	// when using "ClampToBorder" type of wrapping
	void setBorderColor
	(
		float r,   // Red factor
		float g,   // Green factor
		float b,   // Blue factor
		float a    // Alpha factor
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

	// Setter: disactivates current texture
	static void resetCurrentTexture();

private:
	unsigned char* image;  // Image resources
	GLuint textureID;      // openGL ID of texture object
	float* borderColor;    // Color of borders, which is seted when using 'ClampToBorder' type of wrapping
	int width;             // Width of image
	int height;            // Height of image
};

#endif

