#ifndef CAMERA_H
#define CAMERA_H

#include "context\glew.h"

#include "glm\glm.hpp"

/*
    This class represents a virtual camera; object of this type
	stores its own 'world' coordinates and rotation angles
*/
class SGCamera
{
public:

	// Constructor: sets angles to default values
	// and position to 0.0
	SGCamera();

	// Constructor: sets angles to default values
	// and position to x, y, z
	SGCamera
	(
		float x,
		float y, 
		float z
	);

	// Getter: sets specified variables to the current x,y,z values
	void getPosition
	(
		float& x,
		float& y,
		float& z
	);

	// Getter: returns x-position of the camera
	float getPositionX();

	// Getter: returns y-position of the camera
	float getPositionY();

	// Getter: returns z-position of the camera
	float getPositionZ();

	// Getter: returns current yaw angle
	float getYaw();

	// Getter: returns current pitch angle
	float getPitch();

	// Setter: sets new position of the camera
	void setPosition
	(
		float x,
		float y,
		float z
	);

	// Setter: sets new yaw angle
	void setYaw
	(
		float newYaw
	);

	// Setter: sets new pitch angle
	void setPitch
	(
		float newPitch
	);

private:
	glm::vec3 position;  // Camera position
	GLfloat yaw;         // Yaw angle
	GLfloat pitch;       // Pitch angle
};

#endif
