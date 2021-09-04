#pragma once
#include "GameState.h"
#include  <vector>
class GameObject;

class Player1WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
	static Player1WinState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Player1WinState();
		}
		return s_pInstance;
	}
private:
	static void s_restartToPlay();
	static void s_exitFromMenu();
	static const std::string s_gameOverID;

	Player1WinState() {}
	static Player1WinState* s_pInstance;
};
