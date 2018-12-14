#ifndef SHADER_H
#define SHADER_H

#include "context\glew.h"

/* 
   This class represents a shader program, which can be used by 
   openGL for drawing models and textures
*/

class Shader
{
public:
	GLuint Program;  // openGL ID of shader program object

	// Constructor: gets path to vertex/fragment shader code file
	// and builds shader program
	Shader
	(
		const GLchar* vertexPath, 
		const GLchar* fragmentPath
	);

	// Sets this shader program as current,
	// openGL will use this shader program for next drawing operations 
	void Use();
};

#endif 
