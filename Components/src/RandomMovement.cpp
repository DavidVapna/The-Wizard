//=============================================================================
#include "RandomMovement.h"
//=============================================================================
RandomMovement::RandomMovement(sf::Sprite* sprite, b2Body* body)
	:Movement(sprite, body), m_wallCollided(false), m_stepsCounter(30)
{
	m_direction = Direction::Left;
	m_isJumping = false;
}
//=============================================================================
void RandomMovement::update(const float& deltaTime)
{
	m_stepsCounter--;
	if (m_stepsCounter <= 0)
	{
		if (m_direction == Direction::Left)
			setDirection(Direction::Right);
		else if(m_direction == Direction::Right)
			setDirection(Direction::Left);

		m_stepsCounter = 40;
	}
}
//=============================================================================
void RandomMovement::wallColided()
{
	m_wallCollided = true;
}
//=============================================================================
