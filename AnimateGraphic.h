#pragma once
#include "SDLGameObject.h"

class AnimateGraphic : public SDLGameObject
{
private:
	int m_animSpeed;
public:
	AnimateGraphic(const LoaderParams* pParams, int animSpeed);
	virtual void update();
};
