#include "camera.h"

SGCamera::SGCamera()
{
	yaw = -90.0f;
	pitch = 0.0f;
	roll = -90.0f;
	position = glm::vec3(0.0f, 0.0f, 0.0f);
}
SGCamera::SGCamera(float x, float y, float z)
{
	yaw = -90.0f;
	pitch = 0.0f;
	roll = -90.0f;
	position = glm::vec3(x, y, z);
}
void SGCamera::getPosition(float& x, float& y, float& z)
{
	x = position.x;
	y = position.y;
	z = position.z;
}
float SGCamera::getYaw()
{
	return yaw;
}
float SGCamera::getPitch()
{
	return pitch;
}
float SGCamera::getRoll()
{
	return roll;
}
void SGCamera::setPosition(float x, float y, float z)
{
	position = glm::vec3(x, y, z);
}
void SGCamera::setYaw(float newYaw)
{
	yaw = newYaw;
}
void SGCamera::setPitch(float newPitch)
{
	pitch = newPitch;
}
void SGCamera::setRoll(float newRoll)
{
	roll = newRoll;
}