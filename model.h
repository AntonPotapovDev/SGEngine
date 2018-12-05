#ifndef MODEL_H
#define MODEL_H

#include "context/glew.h"
#include "texture.h"

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
	// using data from specified file and sets new texture of the model
	SGModel
	(
		const char* path,      // Path to file
		SGTexture* newTexture
	);

	// Constructor: fills the vertex coordinates array 
	// using data from specified array and sets new texture of the model
	SGModel
	(
		GLfloat* newCoords,    // Pointer to vertex coordinates array
		int length,            // Length of vertex coordinates array
		SGTexture* newTexture
	);

	// Destruction method: frees up model resources
	void free();

	// Setter: sets the order in which openGL will draw vertices
	// (loads array of indices to IBO)
	// (it necessary to be set only if you want to use 'drawWithIBO()')
	// (calling this method more than one time is not recomended)
	void setOrderOfVertices
	(
		int* order   // Order of vertices
	);

	// Getter: returns the pointer to the vertex array of the model
	GLfloat getCoords();

	// Getter: returns count of vertices of the model
	int getCountOfVertices();

	// Getter: returns the texture of the model
	SGTexture getTexture();

	// Getter: returns ID of vertex buffer object
	GLuint getVBO();

	// Getter: returns ID of vertex array object
	GLuint getVAO();

	// Getter: returns ID of index buffer object
	GLuint getIBO();

	// Draws model using default order of vertices  
	void draw();

	// Draws model using the order which is setted in IBO
	void drawWithIBO();

private:
	GLfloat* coords;      // 3D-Coordinates of the model
	int countOfVertices;  // Count of 3D-Coordinates of the model
	SGTexture* texture;   // Pointer to texture of the model
	GLuint VBO;           // Vertex buffer object
   	GLuint VAO;           // Vertex array object
	GLuint IBO;           // Index buffer object
};

#endif 

