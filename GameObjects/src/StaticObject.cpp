//=============================================================================
#include "StaticObject.h"
//=============================================================================
StaticObject::StaticObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:GameObject(world, bodyT, pos, rotation, size, gameObj){}
//=============================================================================
void StaticObject::update(const float& deltaTime)
{
	auto position = m_body->GetPosition();
	m_sprite.setPosition(position.x * SCALE, position.y * SCALE);
	m_animation->play("Default", deltaTime);
}