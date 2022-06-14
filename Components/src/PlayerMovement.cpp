//=============================================================================
#include "PlayerMovement.h"
//=============================================================================
PlayerMovement::PlayerMovement(sf::Sprite* sprite, b2Body* body, int* numFootContacts)
	:Movement(sprite, body),m_numFootContacts(numFootContacts) ,m_jumpTimeout(0)
{
	
}
//=============================================================================
void PlayerMovement::update(const float& deltaTime)
{
	m_jumpTimeout--;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		setDirection(Direction::Left);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		setDirection(Direction::Right);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) &&
		*m_numFootContacts >= 1 &&
		m_jumpTimeout <= 0)
	{
		jump(deltaTime);
		m_jumpTimeout = 15;
	}
}
//=============================================================================
