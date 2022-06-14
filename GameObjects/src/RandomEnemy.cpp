
//=============================================================================
#include "RandomEnemy.h"
#include "RandomMovement.h"
//=============================================================================
bool RandomEnemy::m_registerit = Factory<MovingObject>::registerit("RandomEnemy",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<MovingObject>
	{ return std::make_unique<RandomEnemy>(world, bodyT, pos, rotation, size, gameObj); });
//=============================================================================
RandomEnemy::RandomEnemy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:Enemy(world, bodyT, pos, rotation, size, gameObj)
{
	m_moveComp = std::make_unique<RandomMovement>(&m_sprite, m_body);
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//=============================================================================
void RandomEnemy::wallCollision()
{
	auto* temp = static_cast<RandomMovement*>(m_moveComp.get());
	if (!temp)
	{
		//throw
		return;
	}
	temp->wallColided();
}
//=============================================================================