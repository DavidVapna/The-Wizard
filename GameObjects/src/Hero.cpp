//============================================================================
#include "Hero.h"
#include "PlayerMovement.h"
//============================================================================

//============================================================================
Hero::Hero(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_moveComp = std::make_unique<PlayerMovement>(&m_sprite, m_body, &m_numFootContacts);

	//	sensors.SetAsBox((size.x) / (SCALE * 2), 1 / (SCALE * 2), b2Vec2(0, size.y / (2.f * SCALE)), 0);
	//setFixture(sensors, 1.f, 1.f, 0.f, (uint16)CategoryBits::,
	//	(uint16)CategoryBits::Block | (uint16)CategoryBits::Boundries, true, FEET_DATA);
}
//============================================================================