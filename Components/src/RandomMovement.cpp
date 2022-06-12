//=============================================================================
#include "RandomMovement.h"
//=============================================================================
RandomMovement::RandomMovement(sf::Sprite* sprite, b2Body* body)
	:Movement(sprite, body), m_wallCollided(false)
{

}
//=============================================================================
void RandomMovement::update(const float& deltaTime)
{
	if (m_wallCollided)
	{
		m_wallCollided = false;
		if (m_direction == Direction::Left)
			m_direction = Direction::Right;
		else
			m_direction == Direction::Left;
	}
}
//=============================================================================
void RandomMovement::wallColided()
{
	m_wallCollided = true;
}
//=============================================================================
