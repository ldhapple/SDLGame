#pragma once
#include "Vector2D.h"
#include <SDL.h>
#include <iostream>
#include "LoaderParams.h"

class SDLGameObject
{
public:
	SDLGameObject(const LoaderParams* pParams);
	virtual void draw();
	virtual void update() = 0;
	virtual void clean() {};
	virtual void GetTransparency();
	virtual void RestoreTransparency();
	Vector2D getPosition() const { return m_position; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	

protected:

	Vector2D m_position;
	Vector2D m_velocity;
	Vector2D m_acceleration;

	int m_x;
	int m_y;
	int m_width;
	int m_height;
	int m_currentRow;
	int m_currentFrame;
	std::string m_textureID;


	int m_numFrames;
};
