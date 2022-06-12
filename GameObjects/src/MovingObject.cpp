//=============================================================================
#include "MovingObject.h"
//=============================================================================

//=============================================================================

MovingObject::MovingObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size, gameObj)
{
	setAnimation(size, gameObj);

	//b2PolygonShape polygonShape;
	//polygonShape.SetAsBox(0.3, 0.3, b2Vec2(0, -2), 0);
	//myFixtureDef.isSensor = true;
	//b2Fixture* footSensorFixture = m_body->CreateFixture(&myFixtureDef);
	//footSensorFixture->SetUserData((void*)3);
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
void MovingObject::move(const float& deltaTime)
{

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