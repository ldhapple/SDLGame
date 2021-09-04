#include "GameStateManager.h"

void GameStateManager::popState()
{
	changeState(m_prevState);
}

void GameStateManager::changeState(GameState *pState)
{
	if (pState != NULL)
	{
		if (m_currentState != NULL)
		{
			m_prevState = m_currentState;
			m_currentState->onExit();
		}

		m_currentState = pState;
		m_currentState->onEnter();
	}
}

void GameStateManager::update()
{
	if (m_currentState != NULL)
	{
		m_currentState->update();
	}
}

void GameStateManager::render()
{
	if (m_currentState != NULL)
	{
		m_currentState->render();
	}
}