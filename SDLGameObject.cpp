#include "SDLGameObject.h"
#include "Game.h"

//GameObject(pParams),
SDLGameObject::SDLGameObject(const LoaderParams* pParams) : m_position(pParams->getX(), pParams->getY()), m_velocity(0.0f, 0.0f), m_acceleration(0.0f, 0.0f)
{
	m_width = pParams->getWidth();
	m_height = pParams->getHeight();
	m_textureID = pParams->getTextrueID();
	m_currentRow = 1;
	m_currentFrame = 0;
}

void SDLGameObject::draw()
{
	TextureManager::Instance()->drawFrame(m_textureID, (int)m_position.getX(), (int)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame, 
		TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
	m_velocity += m_acceleration;
	m_position += m_velocity;
}

void SDLGameObject::GetTransparency()
{
	m_currentFrame = 5;
}

void SDLGameObject::RestoreTransparency()
{
	m_currentFrame = 0;
}