#include "Game.h"
#include "Player1WinState.h"
#include "Player1.h"
#include "Player2.h"
#include "MenuButton.h"

const std::string Player1WinState::s_gameOverID = "GAMEOVER";
Player1WinState* Player1WinState::s_pInstance = NULL;

void Player1WinState::s_restartToPlay()
{
	TheGame::Instance()->getStateManager()->changeState(PlayState::Instance());
	Player1::Instance()->Restart();
	Player2::Instance()->Restart();
}

void Player1WinState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

bool Player1WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"Assets/Player1Win.png",
		"player1win",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	if (!TheTextureManager::Instance()->load(
		"Assets/resume0.png",
		"resumebutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"Assets/exit.png",
		"exitbutton",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}

	SDLGameObject* button1 = new MenuButton(
		new LoaderParams(330, 400, 400, 154, "resumebutton"), s_restartToPlay);
	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(330, 600, 400, 120, "exitbutton"), s_exitFromMenu);
	SDLGameObject* winimg = new JustImage(
		new LoaderParams(250, 75, 512, 260, "player1win"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(winimg);
	return true;
}

void Player1WinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Player1WinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool Player1WinState::onExit()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->clean();
	}
	m_gameObjects.clear();

	TheTextureManager::Instance()
		->clearFromTextureMap("resumebutton");
	TheTextureManager::Instance()
		->clearFromTextureMap("exitbutton");
	return true;
}