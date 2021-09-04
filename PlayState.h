#pragma once
#include "SDLGameObject.h"
#include "GameState.h"
#include "Floor.h"
class PlayState : public GameState
{
public:
	static PlayState* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new PlayState();
		}
		return s_pInstance;
	}

	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_playID; }
	bool checkOnCollision(SDLGameObject* p1, SDLGameObject* p2);
	bool checkWalkCollision(SDLGameObject* p1, SDLGameObject* p2);
	bool checkOnFloor(SDLGameObject* player);
	void PushBack(SDLGameObject* _gameObject);
	void DeleteObject();
private:
	static const std::string s_playID;
	PlayState() {};
	static PlayState* s_pInstance;


};