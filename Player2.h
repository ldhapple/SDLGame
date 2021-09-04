#pragma once
#include "Player.h"
#include "JustImage.h"


class Player2 : public Player
{
public:
	static Player2* Instance()
	{
		if (s_pInstance == 0) {
			TheTextureManager::Instance()->load("assets/2pAnim/walkAnim.png", "player2", TheGame::Instance()->getRenderer()); //2P Player
			s_pInstance = new Player2(new LoaderParams(800, 100, 100, 105, "player2"));
		}
		return s_pInstance;
	}

	virtual void draw();
	virtual void update();
	virtual void clean();

	void Walk();
	void Jump();
	void clear();
	void OnFloor() { m_velocity.setY(0); canJump = true; }
	void NotOnFloor() { m_velocity.setY(4); canJump = false; }
	void Fire();
	void Hit(int direction);
	void Reload();
	void Restart() {
		m_position.setX(800); m_position.setY(100); bullet = 2;
		reload = true;
		for (int i = 0; i < 2; i++)
		{
			bullets[i]->RestoreTransparency();
		}
	}
	SDLGameObject* getBullet1(){ return bullet2P1; }
	SDLGameObject* getBullet2() { return bullet2P2; }
private:
	Player2(const LoaderParams* pParams);
	static Player2* s_pInstance;
	bool leftSee = true;
	bool canJump = false;
	bool ctrlKeyDown = false;
	bool reload = false;
	bool canMove = true;
	int bullet = 2;
	SDLGameObject* bullet2P1 = new JustImage(new LoaderParams(710, 30, 100, 100, "bullet"));
	SDLGameObject* bullet2P2 = new JustImage(new LoaderParams(660, 30, 100, 100, "bullet"));
	std::vector<SDLGameObject*> bullets;
};