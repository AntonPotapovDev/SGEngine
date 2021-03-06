#ifndef GWINDOW_H
#define GWINDOW_H

#define GLEW_STATIC
#include "context\glew.h"
#include "context\glfw3.h"

// Simple list for storing context parametrs
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
	// Constructor: sets screen sizes, screen name and context parametrs
	GWindow
	(
		int width,
		int height,
		const char* name,
		int majorV,           // Major version of openGL
		int minorV,           // Minor version of openGL
		float newAngleOfProj,
		float newMinViewDist,
		float newMaxViewDist
	);

	// Destructor: frees up context resources
	~GWindow();

	// Setter: sets context parameters by GLFW-keys
	void setParameter
	(
		int par,      // GLFW-key
		int newValue  // New parameter value
	);

	// Setter: sets window resizable
	void setResizable
	(
		bool resizable
	);

	// Setter: sets cursor enable
	void setCursorEnable(bool enabled);

	// Setter: sets the function that the context 
	// will use to handle key pressing
	void setKeyCallback
	(
		GLFWkeyfun func // this type requires signature: void ... (GLFWwindow*, int, int, int, int)
	);

	// Setter: sets the function that the context
	// will use to handle the mouse movement
	void setCursorPosCallback
	(
		GLFWcursorposfun func // this type requires signature: void ... (GLFWwindow*, double, double)
	);

	// Setter: sets the color that is used for clearing screen
	void setClearColor
	(
		GLfloat r,  // Red factor
		GLfloat g,  // Green factor
		GLfloat b,  // Blue factor
		GLfloat a   // Alpha factor
	);

	// Checks for events, this method should be called 
	// at the beginning of each pass of the 'Game' cycle 
	void pollEvents();

	// Swaps screen buffer with back bufeer to update image, this method should be called
	// at the end of each pass of the 'Game' cycle
	void swapBuffers();

	// Clears screen, optionally clears depth buffer
	void clear
	(
		bool needToClearDepth
	);

	// Getter: returns pointer to the GLFW-window-object
	GLFWwindow* getWindow();

	// Getter: returns time that was took to draw last frame
	// It doesn't work correctly if pollEvents() is used incorrectly
	GLfloat getDeltaTime();

	// Getter: returns current time
	GLfloat getTime();

	// Getter: returns screen width
	int getWidth();

	// Getter: returns screen height
	int getHeight();

	// Getter: returns view angle
	GLfloat getViewAngle();

	// Getter: returns maximum view distance 
	GLfloat getMaxViewDistance();

	// Getter: returns minimum view distance
	GLfloat getMinViewDistance();

	// Getter: returns the boolean value: 
	// true - context has got the command to close current window 
	// fales - closing current window is not required
	bool shouldClose();

private:
	GLFWwindow* window; // GLFW-window-object
	int screenWidth;
	int screenHeight;

	GLfloat viewAngle;    // Angle of projection
	GLfloat minViewDist;  //  
	GLfloat maxViewDist;  // 

	GLfloat currentFrame; // The time when the current frame has been started to draw
	GLfloat lastFrame;    // The 'currentFrame' of previous frame
	GLfloat deltaTime;    // The time that was took to draw previous frame
	GLfloat* clearColor;  // The color that is used for clearing screen
};

#endif 