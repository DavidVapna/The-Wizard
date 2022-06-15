//=============================================================================
#include "MovingObject.h"
//=============================================================================

//=============================================================================

MovingObject::MovingObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size),
	m_numFootContacts(0)
{
	setAnimation(size, gameObj);

	b2PolygonShape feetSensorShape;
	feetSensorShape.SetAsBox((size.x) / (SCALE * 6), 1 / (SCALE * 2), b2Vec2(0, size.y / (2.f * SCALE)), 0);
	setFixture(feetSensorShape, 1.f, 1.f, 0.f, (uint16)CategoryBits::FeetSensor,
		(uint16)CategoryBits::Block | (uint16)CategoryBits::Boundries | (uint16)CategoryBits::Glinda, true, FEET_DATA);
}
//=============================================================================
void MovingObject::setAnimation(const sf::Vector2f& size, int theObject)
{
	auto& texture = Resources::instance().getTexture(theObject);
	m_animation = std::make_unique<Animation>(m_sprite, texture);
	auto start = sf::Vector2i{ 0,0 };

	auto animSpeed = 100.f;

	auto AnimStartIdle = sf::Vector2i(0, 0);/*starting row and col*/
	auto AnimInRowIdle = sf::Vector2i(4, 0);/*(images per row, current row*/

	m_animation->addAnimation("IDLE", animSpeed, AnimStartIdle, AnimInRowIdle, LION_ANIM);

	m_sprite.setScale(size.x / m_sprite.getTextureRect().width, size.y / m_sprite.getTextureRect().height);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f);
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
		m_animation->play("IDLE", deltaTime);
		break;

		//case Direction::Right:
		//	m_animation->play("WALKING", deltaTime);
		//	break;
	}
}
//=============================================================================
void MovingObject::footContact(int val)
{
	m_numFootContacts += val;
}
//=============================================================================
