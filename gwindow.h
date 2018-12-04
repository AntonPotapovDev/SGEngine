#ifndef GWINDOW_H
#define GWINDOW_H

#define GLEW_STATIC
#include "context\glew.h"
#include "context\glfw3.h"

// Simple list for context parametrs
// It isn't used in this patch 
#pragma region Source
class GWPnode
{
public:
	GWPnode()
	{
		next = NULL;
		keyValue = new int[2];
	}
	GWPnode(int key, int value) :
		GWPnode()
	{
		keyValue[0] = key;
		keyValue[1] = value;
	}
	~GWPnode()
	{
		delete[] keyValue;
		if (next != NULL)
			delete next;
	}
	void setNext(int key, int value)
	{
		next = new GWPnode(key, value);
	}
	GWPnode* getNext()
	{
		return next;
	}
	int getKey()
	{
		return keyValue[0];
	}
	int getValue()
	{
		return keyValue[1];
	}

private:
	GWPnode* next;
	int* keyValue;
};

class GWPlist
{
public:
	GWPlist()
	{
		head = NULL;
	}
	GWPlist(int key, int value)
	{
		head = new GWPnode(key, value);
	}
	~GWPlist()
	{
		delete head;
		head = NULL;
	}
	GWPnode* getHead()
	{
		return head;
	}
	void add(int key, int value)
	{
		while (true)
		{
			GWPnode* currentNode = head;
			if (currentNode->getNext() != NULL)
			{
				currentNode = currentNode->getNext();
			}
			else
			{
				currentNode->setNext(key, value);
				break;
			}
		}
	}

private:
	GWPnode* head;
};
#pragma endregion

/*
   This class represents a graphical window and 
   provide context for inputting and outputting 
*/
class GWindow
{
public:
	GWindow(int width, int height, const char* name, int majorV, int minorV);
	~GWindow();
	void setParameter(int par, int newValue);
	void setResizable(bool resizable);
	void setCursorEnable(bool enabled);
	void setKeyCallback(GLFWkeyfun func);
	void setCursorPosCallback(GLFWcursorposfun func);
	void pollEvents();
	void swapBuffers();
	GLFWwindow* getWindow();
	int getWidth();
	int getHeight();
	bool windowShouldClose();

private:
	GLFWwindow* window;
	//GWPlist parametrs;
	int screenWidth;
	int screenHeight;
};

#endif 