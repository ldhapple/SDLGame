#include "Bullet.h"
#include "Player1.h"
#include "Player2.h"
#include "PlayState.h"

Bullet::Bullet(const LoaderParams* pParams) : SDLGameObject(pParams) {}

void Bullet::draw()
{
	SDLGameObject::draw();
}

void Bullet::update()
{
	m_velocity.setX(20 * direction);
	m_velocity.setY(0);
	SDLGameObject::update();
	/*if (m_position.getX() < 0 || m_position.getX() > 1000)
	{
		PlayState::Instance()->DeleteObject();
	}*/
	if (checkOnCollision(Player1::Instance()) && direction < 0 && hitP1 == false)
	{
		Player1::Instance()->Hit(direction);
	}

	if (checkOnCollision(Player1::Instance()) && direction > 0 && hitP1 == false)
	{
		Player1::Instance()->Hit(direction);
	}

	if (checkOnCollision(Player2::Instance()) && direction < 0 && hitP2 == false)
	{
		Player2::Instance()->Hit(direction);
	}

	if (checkOnCollision(Player2::Instance()) && direction > 0 && hitP2 == false)
	{
		Player2::Instance()->Hit(direction);
	}
	

}

void Bullet::Direction(int _direction)
{
	direction = _direction;
}

void Bullet::clean()
{

}

void Bullet::clear()
{

}

bool Bullet::checkOnCollision(SDLGameObject* p1)
{
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = this->getPosition().getX();
	rightA = this->getPosition().getX() + this->getWidth();
	topA = this->getPosition().getY();
	bottomA = this->getPosition().getY() + this->getHeight();

	leftB = p1->getPosition().getX();
	rightB = p1->getPosition().getX() + p1->getWidth();
	topB = p1->getPosition().getY();
	bottomB = p1->getPosition().getY() + p1->getHeight();
	if (bottomA <= topB) 
	{
		return false; 
	}
	if (topA >= bottomB)
	{
		return false; 
	}
	if (rightA <= leftB)
	{ 
		return false; 
	}
	if (leftA >= rightB) 
	{ 
		return false; 
	}

	return true;
}