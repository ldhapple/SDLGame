#include "Game.h"
#include "AnimateGraphic.h"

AnimateGraphic::AnimateGraphic(const LoaderParams* pParams, int animSpeed): SDLGameObject(pParams), m_animSpeed(animSpeed)
{}

void AnimateGraphic::update()
{
	m_currentFrame = int(((SDL_GetTicks() / (650 / m_animSpeed)) % 100000));
}