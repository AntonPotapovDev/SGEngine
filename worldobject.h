#ifndef WORLD_OBJECT_H
#define WORDL_OBJECT_H

#include "model.h"
#include "texture.h"
#include "shader.h"

#include "glm\glm.hpp"

/*
    This class represents an object in 3D graphic world.
	It has its model, 3D position coordinates, rotation and scale,
	which are stored in 4x4 matrices.
	World objects can be drawn by openGL.
*/
class SGWorldObject
{
public:

	// Constructor: initializes SGWorld Object using a pointer to the model object
	SGWorldObject
	(
		SGModel* newModel
	);

	// Getter: the variables specified by the references will be
	// initialized by the corresponding position coordinates
	void getPosition
	(
		float& x,  
		float& y,
		float& z
	);

	// Getter: the variables specified by the references will be
	// initialized by the corresponding rotation factors and angle
	void getRotation
	(
		float& angle,
		float& x,
		float& y,
		float& z
	);

	// Getter: the variables specified by the references will be
	// initialized by the corresponding scale factors
	void getScale
	(
		float& x,
		float& y,
		float& z
	);

	// Setter: sets the position of world object
	void setPosition
	(
		float x,
		float y,
		float z 
	);

	// Setter: sets the position of world object on axis X
	void setPositionX
	(
		float x
	);

	// Setter: sets the position of world object on axis Y
	void setPositionY
	(
		float y
	);

	// Setter: sets the position of world object on axis Z
	void setPositionZ
	(
		float z
	);

	// Setter: sets rotation of world objects using angle (degrees) 
	// and factors of axes x, y, z
	void setRotation
	(
		float angle, 
		float x,
		float y, 
		float z
	);

	// Setter: sets the scale of world object using factors of axes x, y, z
	void setScale
	(
		float x, 
		float y, 
		float z
	);

	// Moves world object along specified vector 
	void move
	(
		float x,  // vector.x
		float y,  // vector.y
		float z   // vecotr.z
	);

	// Rotates world object
	void rotate
	(
		float angle,
		float x,
		float y,
		float z
	);

private:
	SGModel* model;              // Model of object (pointer)
	glm::vec3 position;          // Position vector
	glm::vec3 rotationFactors;   // Vector of rotation factors
	GLfloat rotationAngle;       // Angle of rotation of object
	glm::vec3 scale;             // Scale of object
};

#endif