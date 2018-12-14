#ifndef WORLD_H
#define WORDL_H

#include "gwindow.h"
#include "camera.h"
#include "worldobject.h"

/*
    This class represents a 3D graphical world which can be drawn by openGL.
	Object of this type stores pointers to window object (GWindow) and camera object (SGCamera)
*/
class SGWorld
{
public:
	// Constructor: creates a world object and sets all pointers to NULL
	SGWorld();

	// Constructor: creates a world object and sets its window and camera 
	SGWorld
	(
		GWindow* window, 
		SGCamera* camera
	);

	// Draw specified array of SGWorldObject's 
	void draw
	(
		SGWorldObject* toDraw, // Pointer to first element of array
		int length  // Length of array
	);

private:
	GWindow* window;   // Window object
	SGCamera* camera;  // Camera object
};

#endif
