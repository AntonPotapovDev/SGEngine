#ifndef MODEL_H
#define MODEL_H

#include "context/glew.h"
#include "texture.h"
#include "shader.h"

/*
    This class represents a 3D model. It stores 3D coordinates and
	is used by the constructor of the class 'WorldObject'
*/
class SGModel
{
public:

	// Constructor: generates buffer-objects 
	// and sets all pointers to NULL
	SGModel();

	// Constructor: fills the vertex coordinates array 
	// using data from specified file, sets new texture of the model 
	SGModel
	(
		const char* path,      // Path to file
		SGTexture* newTextures
	);

	// Constructor: fills the vertex coordinates array 
	// using data from specified array, sets new texture of the model
	SGModel
	(
		GLfloat* newCoords,    // Pointer to vertex coordinates array
		int length,            // Length of vertex coordinates array
		SGTexture* newTextures
	);

	// Destruction method: frees up model resources
	void free();

	// Setter: sets the order in which openGL will draw vertices
	// (loads array of indices to IBO)
	// (it necessary to be set only if you want to use 'drawWithIBO()')
	// (calling this method more than one time is not recomended)
	void setOrderOfVertices
	(
		int* order,   // Order of vertices
		int length    // Length of order array
	);

	// Getter: returns the pointer to the vertex array of the model
	GLfloat* getCoords();

	// Getter: returns count of vertices of the model
	int getCountOfVertices();

	// Getter: returns the textures of the model (pointer)
	SGTexture* getTexture();

	// Getter: returns the list with names of uniforms
	//SGList<const char*>* getListOfUniformNames();

	// Getter: returns ID of vertex buffer object
	GLuint getVBO();

	// Getter: returns ID of vertex array object
	GLuint getVAO();

	// Getter: returns ID of index buffer object
	GLuint getIBO();

private:
	GLfloat* coords;      // 3D-Coordinates of the model
	int countOfVertices;  // Count of 3D-Coordinates of the model
	SGTexture* texture;   // Pointer to texture of the model
	//int countOfTextures;  // Count of textures of the model
	//SGList<const char*>* listOfUniformNames  // Names of texture uniforms
	GLuint VBO;           // Vertex buffer object
   	GLuint VAO;           // Vertex array object
	GLuint IBO;           // Index buffer object
};

#endif 

