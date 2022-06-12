//=============================================================================
#include "StaticObject.h"
//=============================================================================
StaticObject::StaticObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size, gameObj)
{
	setAnimation(size, gameObj);
}
//=============================================================================
void StaticObject::setAnimation(const sf::Vector2f& size, int theObject)
{
	m_animation = nullptr;
	m_sprite.setTexture(Resources::instance().getTexture(theObject));

	m_sprite.setScale(size.x / m_sprite.getTextureRect().width, size.y / m_sprite.getTextureRect().height);
	m_sprite.setOrigin(m_sprite.getTextureRect().width / 2.f, m_sprite.getTextureRect().height / 2.f);

}
//=============================================================================
void StaticObject::update(const float& deltaTime)
{
	auto position = m_body->GetPosition();
	position *= SCALE;
	m_sprite.setPosition(position.x, position.y);
}