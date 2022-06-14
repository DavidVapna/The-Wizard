//=============================================================================
#include "Enemy.h"
//=============================================================================

//=============================================================================
Enemy::Enemy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj)
{
	b2PolygonShape shape;
	shape.SetAsBox((size.x / 2.f) / SCALE, (size.y / 2.f) / SCALE);

	setFixture(shape, 1.f, 1.f, 0.f, (uint16)CategoryBits::Enemy,
		(uint16)CategoryBits::Hero | (uint16)CategoryBits::Enemy |
		(uint16)CategoryBits::Block | (uint16)CategoryBits::Boundries,
		false);
}
//=============================================================================

//=============================================================================