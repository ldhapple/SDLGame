#pragma once
#include "GameState.h"
#include <vector>
#include <string>

class GameStateManager
{
public:
	void changeState(GameState* pState);
	void popState();
	void update();
	void render();

private:
	GameState* m_currentState;
	GameState* m_prevState;
};
