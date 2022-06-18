//=============================================================================
#include "RandomMovement.h"
//=============================================================================
RandomMovement::RandomMovement(sf::Sprite* sprite, b2Body* body)
	:Movement(sprite, body), m_wallCollided(false), m_stepsCounter(40)
{
	m_direction = Direction::Left;
}
//=============================================================================
void RandomMovement::update(const float& deltaTime)
{
	m_stepsCounter--;
	if (m_stepsCounter <= 0)
	{
		if (m_direction == Direction::Left)
			m_direction = Direction::Right;
		else
			m_direction == Direction::Left;

		m_stepsCounter = 40;
	}
}
//=============================================================================
void RandomMovement::wallColided()
{
	m_wallCollided = true;
}
//=============================================================================
