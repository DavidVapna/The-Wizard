//=============================================================================
#include "MovingObject.h"
//=============================================================================
MovingObject::MovingObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size, gameObj),
	m_numFootContacts(0)
{
	b2PolygonShape sensors;
	sensors.SetAsBox((size.x) / (SCALE * 2), 1 / (SCALE * 2), b2Vec2(0, -2), 0);
	setFixture(sensors, 0.f, 0.f, 0.f, (uint16)CategoryBits::FeetSensor,
		(uint16)CategoryBits::Block | (uint16)CategoryBits::Boundries, true, FEET_DATA);
}
//=============================================================================
void MovingObject::update(const float& deltaTime)
{
	m_moveComp->setIdle();
	m_moveComp->update(deltaTime);
	m_moveComp->move(deltaTime);
	updateAnimation(deltaTime);
}
//=============================================================================
void MovingObject::updateAnimation(const float& deltaTime)
{
	switch (m_moveComp->getDirection())
	{
	case Direction::Idle:
		m_animation->play("IdleL", deltaTime);
		break;
	case Direction::Left:
		m_animation->play("WalkL", deltaTime);
		break;
	case Direction::Right:
		m_animation->play("WalkR", deltaTime);
		break;
	case Direction::Jump:
		m_animation->play("JumpL", deltaTime);
		break;
	default:
		m_animation->play("Default", deltaTime);
		break;
	}
	if (m_moveComp->isJumping())
	{
		switch (m_moveComp->getDirection())
		{
		case Direction::Left:
			m_animation->play("JumpL", deltaTime);
			break;
		case Direction::Right:
			m_animation->play("JumpR", deltaTime);
			break;
		}

	}
}
//=============================================================================
void MovingObject::footContact(int val)
{
	m_numFootContacts += val;
}
//=============================================================================
