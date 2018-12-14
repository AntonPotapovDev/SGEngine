#ifndef WORLD_H
#define WORDL_H

#include "gwindow.h"
#include "camera.h"
#include "worldobject.h"

class SGWorld
{
public:
	SGWorld();

	SGWorld
	(
		GWindow* window, 
		SGCamera* camera
	);

	void draw
	(
		SGWorldObject* toDraw,
		int length
	);

private:
	GWindow* window;
	SGCamera* camera;
};

#endif
