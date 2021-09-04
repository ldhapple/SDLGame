#include "Player1.h"
#include "Bullet.h"
#include "Game.h"
#include <SDL_mixer.h>

Player1* Player1::s_pInstance = NULL;
Player1::Player1(const LoaderParams* pParams) : Player(pParams) 
{
	bullets.push_back(bullet1P1);
	bullets.push_back(bullet1P2);
	bullets.push_back(bullet1P3);
}

void Player1::draw()
{
	//m_currentFrame = int(((SDL_GetTicks() / 100) % 5));
	if (rightSee == true)
	{
		TextureManager::Instance()->drawFrame(m_textureID, (Uint32)m_position.getX(), (Uint32)m_position.getY(), m_width, m_height, m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer());
	}
	else
	{
		TextureManager::Instance()->drawFrame(m_textureID,
			(Uint32)m_position.getX(),
			(Uint32)m_position.getY(),
			m_width, m_height,
			m_currentRow, m_currentFrame,
			TheGame::Instance()->getRenderer(), SDL_FLIP_HORIZONTAL);
	}
}

void Player1::update()
{
	
	m_velocity.setX(0);

	Walk();
	Jump();
	Fire();
	Reload();

	m_currentFrame = int((SDL_GetTicks() / 100) % 4);
	m_acceleration.setX(0);
	SDLGameObject::update();

}

void Player1::Walk()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D)) {
		m_velocity.setX(4);
		m_currentFrame = int((SDL_GetTicks() / 100) % 9);
		rightSee = true;
		canMove = false;
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_D) && !TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A))
	{
		canMove = true;
	}

	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_A)) {
		m_velocity.setX(-4);
		m_currentFrame = int((SDL_GetTicks() / 100) % 9);
		rightSee = false;
		canMove = false;
	}

	

}

void Player1::Jump()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W) && jumpKeyDown == false && canJump == true) {
		m_position.setY(m_position.getY() - 180);
		jumpKeyDown = true;
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_W))
	{
		jumpKeyDown = false;
	}
}

void Player1::Fire()
{
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE) && spaceKeyDown == false)
	{
		TheTextureManager::Instance()->load("assets/1pAnim/1pBullet.png", "bullet1P", TheGame::Instance()->getRenderer());
		Bullet* bullet1 = new Bullet(new LoaderParams(m_position.getX() + 90, m_position.getY() + 30, 50, 20, "bullet1P"));
		Bullet* bullet2 = new Bullet(new LoaderParams(m_position.getX() - 50, m_position.getY() + 30, 50, 20, "bullet1P"));
		Mix_Chunk* fire = Mix_LoadWAV("Assets/1pAnim/Player1Gun.wav");
		spaceKeyDown = true;
		if (bullet > 0)
		{
			if (rightSee == true)
			{
				bullet1->Direction(1);
				PlayState::Instance()->PushBack(bullet1);
				bullet--;
				bullets[bullet]->GetTransparency();
				Mix_PlayChannel(-1, fire, 0);
			}
			else
			{
				bullet2->Direction(-1);
				PlayState::Instance()->PushBack(bullet2);
				bullet--;
				bullets[bullet]->GetTransparency();
				Mix_PlayChannel(-1, fire, 0);
			}
		}

		if (bullet1->getPosition().getX() < 0 || bullet1->getPosition().getX() > 1024)
		{
			TextureManager::Instance()->clearFromTextureMap("bullet1P");
		}

		if (bullet2->getPosition().getX() < 0 || bullet2->getPosition().getX() > 1024)
		{
			TextureManager::Instance()->clearFromTextureMap("bullet1P");
		}
	}

	if (!TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_SPACE))
	{
		spaceKeyDown = false;
	}
}

void Player1::Hit(int direction)
{
	m_position.setX(m_position.getX() + (30 * direction)); //2pBulletPower
}

void Player1::Reload()
{
	
	if (TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_LALT) && bullet < 1 && canJump == true && canMove == true)
	{
		Mix_Chunk* reload = Mix_LoadWAV("Assets/1pAnim/Player1Reload.wav");
		Mix_PlayChannel(-1, reload, 0);
		bullet = 3;
		for (int i = 0; i < 3; i++)
		{
			bullets[i]->RestoreTransparency();
		}
	}


}

void Player1::clean()
{

}

void Player1::clear()
{

}