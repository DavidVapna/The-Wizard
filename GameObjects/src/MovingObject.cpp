//=============================================================================
#include "MovingObject.h"
//=============================================================================

//=============================================================================

MovingObject::MovingObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size, gameObj),
	m_moveComp(&m_sprite, m_body)
{
	setAnimation(size, gameObj);
}
//=============================================================================
void MovingObject::setAnimation(const sf::Vector2f& size, int theObject)
{
	auto& texture = Resources::instance().getTexture(theObject);
	m_animation = std::make_unique<AnimationComponent>(m_sprite, texture);
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
	m_moveComp.setIdle();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		m_moveComp.setDirection(Direction::Left);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		m_moveComp.setDirection(Direction::Right);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) /* && m_body->GetLinearVelocity().y == 0 */)
		m_moveComp.jump(deltaTime);

	m_moveComp.move(deltaTime);
}
//=============================================================================
void MovingObject::update(const float& deltaTime)
{
	auto direction = m_moveComp.getDirection();
	switch (direction)
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