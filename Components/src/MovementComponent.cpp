//=============================================================================
#include "MovementComponent.h"
//=============================================================================

//=============================================================================

MovementComponent::MovementComponent(sf::Sprite* sprite, b2Body* body)
	:m_direction(Direction::Idle),m_sprite(sprite), m_body(body)
{

}
//=============================================================================
MovementComponent::~MovementComponent()
{

}
//=============================================================================
void MovementComponent::move(const float& deltaTime)
{
	b2Vec2 vel = b2Vec2(toVector(m_direction).x * m_speed * deltaTime, (m_body)->GetLinearVelocity().y);
	(m_body)->SetLinearVelocity(vel);
	b2Vec2 position = (m_body)->GetPosition();
	position *= SCALE;
	m_sprite->setPosition(position.x, position.y);
}
//=============================================================================
void MovementComponent::jump(const float& deltaTime)
{
	float force = -m_body->GetMass() * JUMP;
	//m_body->ApplyForce(b2Vec2(0, force), m_body->GetWorldCenter(), true);
	m_body->ApplyLinearImpulse(b2Vec2(0, force), m_body->GetWorldCenter(), true);
	//Resources::getResourceRef().playSound(jumpingSound);
}
//=============================================================================
void MovementComponent::setDirection(Direction dir)
{
	m_direction = dir;
}
//=============================================================================
void MovementComponent::setIdle()
{
	m_direction = Direction::Idle;
}
//=============================================================================
Direction MovementComponent::getDirection() const
{
	return m_direction;
}
//=============================================================================