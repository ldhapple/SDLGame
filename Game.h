#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"
#include <vector>
#include "InputHandler.h"
#include "SDLGameObject.h"
#include "GameStateManager.h"
#include "MenuState.h"
#include "PlayState.h"

class Game {
public:
	static Game* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new Game();
			return s_pInstance;
		}
		return s_pInstance;
	}
	SDL_Renderer* getRenderer() const { return m_pRenderer; }

	~Game() {}
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }
	void quit();
	void pushBack(SDLGameObject* _gameObject);
	GameStateManager* getStateManager() { return m_pGameStateManager; }

	

private:
	Game() {}
	static Game* s_pInstance;
	SDL_Window * m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;
	int m_currentFrame;
	GameStateManager* m_pGameStateManager;
	std::vector<SDLGameObject*> m_gameObjects;

};  typedef Game TheGame;
