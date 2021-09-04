#include "Player.h"

Player::Player(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Player::draw()
{
	m_currentFrame = 0;
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	if (m_velocity.getX() < 0)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(),
			(Uint32)m_position.getY(),
			m_width, m_height,
			m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
}

void Player::Walk()
{
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
	//	m_velocity.setX(4);
	//	m_currentFrame = int((SDL_GetTicks() / 100) % 9);
	//}
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
	//	m_velocity.setX(-4);
	//	m_currentFrame = int((SDL_GetTicks() / 100) % 9);
	//}
	///*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP)) {
	//	m_velocity.setY(-2);
	//}*/
	///*if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN)) {
	//	m_velocity.setY(2);
	//}*/

}

void Player::Jump()
{
	//if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && jumpKeyDown == false) {
	//	m_position.setY(m_position.getY() - 180);
	//	//m_acceleration.setY(-1);
	//	jumpKeyDown = true;
	//}

	//if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	//{
	//	jumpKeyDown = false;
	//}
}

void Player::clean()
{

}

void Player::clear()
{

}

void Player::update()
{

}
