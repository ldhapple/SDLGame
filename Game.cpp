#include <iostream>
#include "Game.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);

		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
	
		m_pGameStateManager = new GameStateManager();
		m_pGameStateManager->changeState(MenuState::Instance());
	}
	else
	{
		return false;
	}
	m_bRunning = true;
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer);

	/*for (std::vector<SDLGameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}*/
	m_pGameStateManager->render();


	SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
	TheInputHandler::Instance()->clean();
}

void Game::quit()
{
	m_bRunning = false;
}

void Game::handleEvents()
{

	TheInputHandler::Instance()->update();
}

void Game::update()
{
	/*for (std::vector<SDLGameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}*/
	m_pGameStateManager->update();

}

void Game::pushBack(SDLGameObject* _gameObject)
{
	m_gameObjects.push_back(_gameObject);
}