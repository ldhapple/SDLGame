#pragma once
#include "SDLGameObject.h"

class JustImage : public SDLGameObject
{
public:
	JustImage(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
};
