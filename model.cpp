#include "model.h"
#include <iostream>
#include <fstream>
#include <stdexcept>


SGModel::SGModel()
{
	coords = NULL;
	textures = NULL;
	countOfVertices = 0;
	VBO = 0;
	VAO = 0;
	IBO = 0;
}
SGModel::SGModel(GLfloat* newCoords, int length, SGTexture* newTextures)
{
	coords = newCoords;
	textures = newTextures;
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
	if (textures != NULL)
		delete textures;
}
void SGModel::setOrderOfVertices(int* order)
{
	try
	{
		glGenBuffers(1, &IBO);

		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(order), order, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	catch (std::exception ex)
	{
		throw std::exception("Error: IBO initialization failed!");
	}
}


