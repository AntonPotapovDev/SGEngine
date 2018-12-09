#include "worldobject.h"
#include <stdexcept>

SGWorldObject::SGWorldObject(SGModel* model)
{
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);
	rotationFactors = glm::vec3(0.0f, 0.0f, 0.0f);
	rotationAngle = 0.0f;
}
void SGWorldObject::getPosition(float& x, float& y, float& z)
{
	x = position.x;
	y = position.y;
	z = position.z;
}
void SGWorldObject::getRotation(float& angle, float& x, float& y, float& z)
{
	angle = rotationAngle;
	x = rotationFactors.x;
	y = rotationFactors.y;
	z = rotationFactors.z;
}
void SGWorldObject::getScale(float& x, float& y, float& z)
{
	x = scale.x;
	y = scale.y;
	z = scale.z;
}
void SGWorldObject::setPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}
void SGWorldObject::setRotation(float angle, float x, float y, float z)
{
	rotationFactors = glm::vec3(x, y, z);
	rotationAngle = angle;
}
void SGWorldObject::setScale(float x, float y, float z)
{
	scale = glm::vec3(x, y, z);
}