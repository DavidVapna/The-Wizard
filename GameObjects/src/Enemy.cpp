//=============================================================================
#include "Enemy.h"
//=============================================================================

//=============================================================================
Enemy::Enemy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//=============================================================================

//=============================================================================