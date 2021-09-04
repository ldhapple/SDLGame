#include "Player2.h"
#include "Bullet.h"
#include <SDL_mixer.h>
Player2* Player2::s_pInstance = NULL;
Player2::Player2(const LoaderParams* pParams) : Player(pParams) 
{
	bullets.push_back(bullet2P1);
	bullets.push_back(bullet2P2);
}

void Player2::draw()
{
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	if (leftSee == true)
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

void Player2::update()
{
	m_velocity.setX(0);
	Walk();
	Jump();
	Fire();
	Reload();

	m_currentFrame = int((SDL_GetTicks() / 100) % 6);
	m_acceleration.setX(0);
	SDLGameObject::update();

}

void Player2::Walk()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT)) {
		m_velocity.setX(4);
		m_currentFrame = int((SDL_GetTicks() / 100) % 9);
		leftSee = false;
		canMove = false;
	}
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT)) {
		m_velocity.setX(-4);
		m_currentFrame = int((SDL_GetTicks() / 100) % 9);
		leftSee = true;
		canMove = false;
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT) && !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
	{
		canMove = true;
	}
}

void Player2::Jump()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP) && jumpKeyDown == false && canJump == true) {
		m_position.setY(m_position.getY() - 180);
		//m_acceleration.setY(-1);
		jumpKeyDown = true;
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
	{
		jumpKeyDown = false;
	}
}

void Player2::Fire()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL) && ctrlKeyDown == false)
	{
		Mix_Chunk* fire = Mix_LoadWAV("Assets/2pAnim/Player2Gun.wav");
		TheTextureManager::Instance()->load("assets/2pAnim/2pBullet.png", "bullet2P", TheGame::Instance()->getRenderer());
		Bullet* bullet1 = new Bullet(new LoaderParams(m_position.getX() + 90, m_position.getY() + 30, 50, 20, "bullet2P"));
		Bullet* bullet2 = new Bullet(new LoaderParams(m_position.getX() - 50, m_position.getY() + 30, 50, 20, "bullet2P"));

		ctrlKeyDown = true;
		if (bullet > 0)
		{
			if (leftSee == true)
			{
				bullet2->Direction(-1);
				PlayState::Instance()->PushBack(bullet2);
				bullet--;
				bullets[bullet]->GetTransparency();
				Mix_PlayChannel(-1, fire, 0);
			}
			else
			{
				bullet1->Direction(1);
				PlayState::Instance()->PushBack(bullet1);
				bullet--;
				bullets[bullet]->GetTransparency();
				Mix_PlayChannel(-1, fire, 0);
			}

			if (bullet1->getPosition().getX() < 0 || bullet1->getPosition().getX() > 1024)
			{
				TextureManager::Instance()->clearFromTextureMap("bullet2P");
			}

			if (bullet2->getPosition().getX() < 0 || bullet2->getPosition().getX() > 1024)
			{
				TextureManager::Instance()->clearFromTextureMap("bullet2P");
			}
		}
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
	{
		ctrlKeyDown = false;
	}
}

void Player2::Hit(int direction)
{
	m_position.setX(m_position.getX() + (20 * direction)); //1pBulletPower
}

void Player2::Reload()
{
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RALT) && bullet < 1 && canJump == true && canMove == true)
	{
		Mix_Chunk* reload = Mix_LoadWAV("Assets/2pAnim/Player2Reload.wav");
		Mix_PlayChannel(-1, reload, 0);
		bullet = 2;
		for (int i = 0; i < 2; i++)
		{
			bullets[i]->RestoreTransparency();
		}
	}

}

void Player2::clean()
{

}

void Player2::clear()
{

}