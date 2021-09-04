#pragma once
#include "GameState.h"
#include  <vector>
class GameObject;

class Player2WinState : public GameState
{
public:
	virtual void update();
	virtual void render();
	virtual bool onEnter();
	virtual bool onExit();
	virtual std::string getStateID() const { return s_gameOverID; }
	static Player2WinState* Instance() {
		if (s_pInstance == 0) {
			s_pInstance = new Player2WinState();
		}
		return s_pInstance;
	}
private:
	static void s_restartToPlay();
	static void s_exitFromMenu();
	static const std::string s_gameOverID;

	Player2WinState() {}
	static Player2WinState* s_pInstance;
};
