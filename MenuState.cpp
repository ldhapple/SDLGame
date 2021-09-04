#include "MenuState.h"
#include "MenuButton.h"
#include "JustImage.h"
#include "TextureManager.h"
#include "Game.h"
#include <iostream>
#include <SDL_mixer.h>
const std::string MenuState::s_menuID = "MENU";
MenuState* MenuState::s_pInstance = NULL;

void MenuState::update()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}
}

void MenuState::render()
{
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw();
	}
}

bool MenuState::onEnter()
{
	//SDL_SetRenderDrawColor(TheGame::Instance()->getRenderer(), 255, 255, 255, 0);

	if (!TheTextureManager::Instance()->load(
		"Assets/title.png",
		"title",
		TheGame::Instance()->getRenderer()))
	{
		return false;
	}
	if (!TheTextureManager::Instance()->load(
		"Assets/start.png",
		"playbutton",
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
		new LoaderParams(330, 400, 400, 120, "playbutton"), s_menuToPlay);
	SDLGameObject* button2 = new MenuButton(
		new LoaderParams(330, 600, 400, 120, "exitbutton"), s_exitFromMenu);
	SDLGameObject* title = new JustImage(
		new LoaderParams(250, 75, 512, 229, "title"));

	m_gameObjects.push_back(button1);
	m_gameObjects.push_back(button2);
	m_gameObjects.push_back(title);

	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
	Mix_Music* bgm = Mix_LoadMUS("Assets/BGM1.mp3");
	Mix_PlayMusic(bgm, -1);
}

bool MenuState::onExit()
{
	return true;
}

void MenuState::s_menuToPlay()
{
	TheGame::Instance()->getStateManager()->changeState(PlayState::Instance());
}

void MenuState::s_exitFromMenu()
{
	TheGame::Instance()->quit();
}