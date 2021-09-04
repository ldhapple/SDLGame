#include "PlayState.h"
#include "Game.h"
#include "JustImage.h"
#include "TextureManager.h"
#include "MenuButton.h"
#include "AnimateGraphic.h"
#include "Player1.h"
#include "Player2.h"
#include "Player1WinState.h"
#include "Player2WinState.h"
#include <iostream>

//#include "GameOverState.h"

const std::string PlayState::s_playID = "PLAY";
PlayState* PlayState::s_pInstance = NULL;

void PlayState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	if (checkOnFloor(Player1::Instance()))
	{
		Player1::Instance()->OnFloor();
	}
	else if (!checkOnFloor(Player1::Instance()))
	{
		Player1::Instance()->NotOnFloor();
	}

	if (checkOnFloor(Player2::Instance()))
	{
		Player2::Instance()->OnFloor();
	}
	else if (!checkOnFloor(Player2::Instance()))
	{
		Player2::Instance()->NotOnFloor();
	}

	if (Player1::Instance()->getPosition().getY() > 768 && Player2::Instance()->getPosition().getY() < 768)
	{
		TheGame::Instance()->getStateManager()->changeState(Player2WinState::Instance());
	}
	else if (Player2::Instance()->getPosition().getY() > 768 && Player1::Instance()->getPosition().getY() < 768)
	{
		TheGame::Instance()->getStateManager()->changeState(Player1WinState::Instance());
	}


}
void PlayState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool PlayState::onEnter()
{
	if (!TheTextureManager::Instance()->load("assets/background.png", "background", TheGame::Instance()->getRenderer())) //배경
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load("assets/1pAnim/downAnim.png", "down", TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	SDLGameObject* background = new JustImage(new LoaderParams(0, 0, 1024, 768, "background"));
	m_gameObjects.push_back(background);

	if (!TheTextureManager::Instance()->load("assets/go0.png", "go", TheGame::Instance()->getRenderer())) //시작 시 start 문구
	{
		return false;
	}
	SDLGameObject* go = new AnimateGraphic(new LoaderParams(400, 250, 190, 300, "go"), 1);
	m_gameObjects.push_back(go);

	if (!TheTextureManager::Instance()->load("assets/1p.png", "1p", TheGame::Instance()->getRenderer())) //1P Image
	{
		return false;
	}
	SDLGameObject* player1Img = new JustImage(new LoaderParams(70, 30, 150, 100, "1p"));
	m_gameObjects.push_back(player1Img);

	if (!TheTextureManager::Instance()->load("assets/2p.png", "2p", TheGame::Instance()->getRenderer())) //2P Image
	{
		return false;
	}
	SDLGameObject* player2Img = new JustImage(new LoaderParams(800, 30, 150, 100, "2p"));
	m_gameObjects.push_back(player2Img);

	SDLGameObject* player1 = Player1::Instance();
	m_gameObjects.push_back(player1);

	SDLGameObject* player2 = Player2::Instance();
	m_gameObjects.push_back(player2);

	if (!TheTextureManager::Instance()->load("assets/wall2.png", "floor", TheGame::Instance()->getRenderer())) //Floor
	{
		return false;
	}
	SDLGameObject* floor1 = new Floor(new LoaderParams(100, 370, 371, 80, "floor"));
	SDLGameObject* floor2 = new Floor(new LoaderParams(200, 600, 650, 90, "floor"));
	SDLGameObject* floor3 = new Floor(new LoaderParams(550, 440, 371, 76, "floor"));
	m_gameObjects.push_back(floor1);
	m_gameObjects.push_back(floor2);
	m_gameObjects.push_back(floor3);

	if (!TheTextureManager::Instance()->load("assets/Play/Bullet.png", "bullet", TheGame::Instance()->getRenderer())) //Bullet
	{
		return false;
	}

	m_gameObjects.push_back(Player1::Instance()->getBullet1());
	m_gameObjects.push_back(Player1::Instance()->getBullet2());
	m_gameObjects.push_back(Player1::Instance()->getBullet3());
	m_gameObjects.push_back(Player2::Instance()->getBullet1());
	m_gameObjects.push_back(Player2::Instance()->getBullet2());

	
	
}

bool PlayState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();
	//TheTextureManager::Instance()->clearFromTextureMap("helicopter");
	return true;
}

void PlayState::PushBack(SDLGameObject* _gameObject)
{
	m_gameObjects.push_back(_gameObject);
}

void PlayState::DeleteObject()
{
	m_gameObjects.pop_back();
}

bool PlayState::checkOnCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }

	return true;
}

bool PlayState::checkWalkCollision(SDLGameObject* p1, SDLGameObject* p2)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY() + p1->getHeight();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX() + 50;
	rightB = p2->getPosition().getX() + p2->getWidth() - 40;
	topB = p2->getPosition().getY() + 20;
	bottomB = p2->getPosition().getY() + 30;
	if (bottomA <= topB) { return false; }
	if (topA >= bottomB) { return false; }
	if (rightA <= leftB) { return false; }
	if (leftA >= rightB) { return false; }

	return true;
}

bool PlayState::checkOnFloor(SDLGameObject* player)
{
	if (checkWalkCollision(player, m_gameObjects[6]) ||
		checkWalkCollision(player, m_gameObjects[7]) ||
		checkWalkCollision(player, m_gameObjects[8]))
	{
		return true;
	}
	else
	{
		return false;
	}
}

