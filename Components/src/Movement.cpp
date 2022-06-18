//=============================================================================
#include "Movement.h"
#include "Resources.h"
//=============================================================================

//=============================================================================

Movement::Movement(sf::Sprite* sprite, b2Body* body)
	:m_direction(Direction::Idle),m_sprite(sprite), m_body(body)
{

}
//=============================================================================
void Movement::move(const float& deltaTime)
{
	b2Vec2 velocity = b2Vec2(toVector(m_direction).x * m_speed * deltaTime, m_body->GetLinearVelocity().y);
	m_body->SetLinearVelocity(velocity);

	b2Vec2 position = m_body->GetPosition();
	m_sprite->setPosition(position.x * SCALE, position.y * SCALE);
}
//=============================================================================
void Movement::jump(const float& deltaTime)
{
	float force = -m_body->GetMass() * JUMP;
	m_body->ApplyLinearImpulse(b2Vec2(0, force), m_body->GetWorldCenter(), true);
}
//=============================================================================
void Movement::setDirection(Direction dir)
{
	m_direction = dir;
}
//=============================================================================
void Movement::setIdle()
{
	m_direction = Direction::Idle;
}
//=============================================================================
Direction Movement::getDirection() const
{
	return m_direction;
}
//=============================================================================
