#pragma once
#include <SDL.h>
#include <map>

class TextureManager
{
private:
	std::map<std::string, SDL_Texture*> m_textureMap;
	std::map<std::string, bool> useTexture;
	static TextureManager* s_pInstance;

	TextureManager() {}

public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void deleteNotUseTexture(std::string id);
	void clearFromTextureMap(std::string id);
}; typedef TextureManager TheTextureManager;