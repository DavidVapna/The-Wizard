//=============================================================================
#include "PlayerMovement.h"
//=============================================================================
PlayerMovement::PlayerMovement(sf::Sprite* sprite, b2Body* body)
	:Movement(sprite, body)
{
	
}
//=============================================================================
void PlayerMovement::update(const float& deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		setDirection(Direction::Left);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		setDirection(Direction::Right);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		jump(deltaTime);
}
//=============================================================================
