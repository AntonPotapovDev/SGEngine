#include "world.h"
#include "shader.h"

#include "glm\glm.hpp"
#include "glm\gtc\matrix_transform.hpp"
#include "glm\gtc\type_ptr.hpp"

SGWorld::SGWorld()
{
	this->window = NULL;
	this->camera = NULL;
}
SGWorld::SGWorld(GWindow* window, SGCamera* camera)
{
	this->window = window;
	this->camera = camera;
}
void SGWorld::draw(SGWorldObject* toDraw, int length)
{
	glm::mat4 projection(1.0f);
	glm::mat4 view(1.0f);

	projection = glm::perspective<GLfloat>(
		window->getViewAngle(), 
		(float)window->getWidth() / (float)window->getHeight(),
		window->getMinViewDistance(), 
		window->getMaxViewDistance() );

	glm::vec3 camPosition(camera->getPositionX(), camera->getPositionY(), camera->getPositionZ());
	glm::vec3 camFront(0.0f, 0.0f, 0.0f);
	camFront.x = cos(glm::radians(camera->getPitch())) * cos(glm::radians(camera->getYaw()));
	camFront.y = sin(glm::radians(camera->getPitch()));
	camFront.z = cos(glm::radians(camera->getPitch())) * sin(glm::radians(camera->getYaw()));

	camFront = glm::normalize(camFront);

	view = glm::lookAt(
		camPosition,
		camPosition + camFront,
		glm::vec3(0.0f, 1.0f, 0.0f) );

	for (int i = 0; i < length; i++)
	{
		SGModel* model = toDraw[i].getModel();
		toDraw[i].getShader()->Use();
		glActiveTexture(GL_TEXTURE0);
		model->getTexture()->setTextureAsCurrent();
		glUniform1i(glGetUniformLocation(
			toDraw[i].getShader()->Program, 
			model->getTextureUnifromName()), 0);

		glm::mat4 modelM(1.0f);
		float x, y, z;
		toDraw[i].getPosition(x, y, z);
		modelM = glm::translate(modelM, glm::vec3(x, y, z));
		float angle;
		toDraw[i].getRotation(angle, x, y, z);
		if (angle != 0.0f)
			modelM = glm::rotate(modelM, angle, glm::vec3(x, y, z));
		toDraw[i].getScale(x, y, z);
		if ( x != 0.0f && y != 0.0f && z != 0.0f &&
			(x != 1.0f || y != 1.0f || z != 1.0f) )
			modelM = glm::scale(modelM, glm::vec3(x, y, z));

		glm::mat4 transform = projection * view * modelM;
		glUniformMatrix4fv(glGetUniformLocation(toDraw[i].getShader()->Program, "SG_transform"), 1, GL_FALSE, glm::value_ptr(transform));

		glBindVertexArray(model->getVAO());
		glDrawArrays(GL_TRIANGLES, 0, model->getCountOfVertices());
		glBindVertexArray(0);
	}
}