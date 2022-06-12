//=============================================================================
#include "Enemy.h"
//=============================================================================
bool Enemy::m_registerit = Factory<MovingObject>::registerit("Dorothy",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<MovingObject>
	{ return std::make_unique<Enemy>(world, bodyT, pos, rotation, size, gameObj); });
//=============================================================================
Enemy::Enemy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//=============================================================================

//=============================================================================