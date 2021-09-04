#pragma once
#pragma once
#include "SDLGameObject.h"

class Bullet : public SDLGameObject
{
public:
	Bullet(const LoaderParams* pParams);
	virtual void draw();
	virtual void update();
	virtual void clean();
	void clear();
	void Direction(int direction);
	bool checkOnCollision(SDLGameObject* p1);
private:
	int direction;
	bool hitP1 = false;
	bool hitP2 = false;
};
