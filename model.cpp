#include "model.h"
#include <iostream>
#include <fstream>
#include <stdexcept>


SGModel::SGModel()
{
	coords = NULL;
	texture = NULL;
	countOfVertices = 0;
	VBO = 0;
	VAO = 0;
	IBO = 0;
}
SGModel::SGModel(GLfloat* newCoords, int length, SGTexture* newTexture)
{
	coords = newCoords;
	texture = newTexture;
	countOfVertices = length;

	try
	{
		glGenBuffers(1, &VBO);
		glGenVertexArrays(1, &VAO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);

		glBufferData(GL_ARRAY_BUFFER, countOfVertices * 5 * sizeof(GLfloat), coords, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
		glEnableVertexAttribArray(1);

		glBindVertexArray(0);
	}
	catch (std::exception ex)
	{
		throw std::exception("Error: model initialization faild!");
	}
}
void SGModel::free()
{
	if (coords != NULL)
		delete coords;
	if (texture != NULL)
		delete texture;
}
void SGModel::setOrderOfVertices(int* order, int length)
{
	try
	{
		glGenBuffers(1, &IBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, length * sizeof(int), order, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	catch (std::exception ex)
	{
		throw std::exception("Error: IBO initialization failed!");
	}
}
GLfloat* SGModel::getCoords()
{
	return coords;
}
int SGModel::getCountOfVertices()
{
	return countOfVertices;
}
SGTexture* SGModel::getTexture()
{
	return texture;
}
GLuint SGModel::getVBO()
{
	return VBO;
}
GLuint SGModel::getVAO()
{
	return VAO;
}
GLuint SGModel::getIBO()
{
	return IBO;
}

