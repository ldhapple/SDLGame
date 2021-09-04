#include "Game.h"
#include "Player2WinState.h"
#include "Player1.h"
#include "Player2.h"
#include "MenuButton.h"

const std::string Player2WinState::s_gameOverID = "GAMEOVER";
Player2WinState* Player2WinState::s_pInstance = NULL;

void Player2WinState::s_restartToPlay()
{
	TheGame::Instance()->getStateManager()->changeState(PlayState::Instance());
	Player1::Instance()->Restart();
	Player2::Instance()->Restart();
}

void Player2WinState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}

bool Player2WinState::onEnter()
{
	if (!TheTextureManager::Instance()->load(
		"Assets/Player2Win.png",
		"player2win",
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
		new LoaderParams(250, 75, 512, 260, "player2win"));
	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(winimg);
	return true;
}

void Player2WinState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void Player2WinState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool Player2WinState::onExit()
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