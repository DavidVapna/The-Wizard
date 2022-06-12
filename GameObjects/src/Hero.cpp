//============================================================================
#include "Hero.h"
//============================================================================

//============================================================================
Hero::Hero(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//============================================================================
//void Hero::update(const float& deltaTime)
//{
//	MovingObject::update(deltaTime);
//}
//============================================================================

//============================================================================
//bool Hero::move(int dirX, bool& moved, int& animPos, float dt, int animDirec)
//{
//    /* dirX * PLAYER_SPEED * dt, m_body->GetLinearVelocity().y;
//}
//============================================================================