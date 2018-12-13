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
void SGWorldObject::setPositionX(float x)
{
	position.x = x;
}
void SGWorldObject::setPositionY(float y)
{
	position.y = y;
}
void SGWorldObject::setPositionZ(float z)
{
	position.z = z;
}
void SGWorldObject::move(float x, float y, float z)
{
	position.x = position.x + x;
	position.y = position.y + y;
	position.z = position.z + z;
}
void SGWorldObject::setRotation(float angle, float x, float y, float z)
{
	rotationFactors = glm::vec3(x, y, z);
	rotationAngle = glm::radians(angle);
}
void SGWorldObject::rotate(float angle, float x, float y, float z)
{
	rotationFactors.x = (rotationFactors.x + x) / 2;
	rotationFactors.y = (rotationFactors.y + y) / 2;
	rotationFactors.z = (rotationFactors.z + z) / 2;
	rotationAngle += glm::radians(angle);
}
void SGWorldObject::setScale(float x, float y, float z)
{
	scale = glm::vec3(x, y, z);
}