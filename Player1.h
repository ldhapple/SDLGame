#pragma once
#include "Player.h"
#include "JustImage.h"

class Player1 : public Player
{
public:
	static Player1* Instance()
	{
		if (s_pInstance == 0) {
			TheTextureManager::Instance()->load("assets/1pAnim/walkAnim.png", "player1", TheGame::Instance()->getRenderer()); //1P Player
			s_pInstance = new Player1(new LoaderParams(100, 100, 100, 105, "player1"));
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
		m_position.setX(100); m_position.setY(100); 	bullet = 3; reload = true;
		for (int i = 0; i < 3; i++)
		{
			bullets[i]->RestoreTransparency();
		}
	
	}
	SDLGameObject* getBullet1() { return bullet1P1; }
	SDLGameObject* getBullet2() { return bullet1P2; }
	SDLGameObject* getBullet3() { return bullet1P3; }


private:
	Player1(const LoaderParams* pParams);
	static Player1* s_pInstance;
	bool rightSee = true;
	bool canJump = false;
	bool spaceKeyDown = false;
	bool reload = false;
	bool canMove = true;
	int bullet = 3;
	SDLGameObject* bullet1P1 = new JustImage(new LoaderParams(200, 30, 100, 100, "bullet"));
	SDLGameObject* bullet1P2 = new JustImage(new LoaderParams(250, 30, 100, 100, "bullet"));
	SDLGameObject* bullet1P3 = new JustImage(new LoaderParams(300, 30, 100, 100, "bullet"));
	std::vector<SDLGameObject*> bullets;

	
};