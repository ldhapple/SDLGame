#pragma once
#include "SDLGameObject.h"
#include "InputHandler.h"
#include "Floor.h"

class Player : public SDLGameObject
{
public:
	Player(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();

	virtual void Walk();
	virtual void Jump();
	void clear();

protected:
	bool jumpKeyDown = false;


};
