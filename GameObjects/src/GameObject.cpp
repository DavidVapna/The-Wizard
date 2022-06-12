//=============================================================================
#include "GameObject.h"
//=============================================================================
GameObject::GameObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:m_colided(false), m_removed(false)
{
	setBody(world, bodyT, pos, rotation);
	setFixture(world, size);
}
//=============================================================================
void GameObject::setBody(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation)
{
	b2BodyDef objBody;
	objBody.position.Set(pos.x / SCALE , pos.y / SCALE);
	objBody.type = (b2BodyType)bodyT;
	objBody.angle = 0;
	//objBody.userData.pointer = reinterpret_cast<uintptr_t>(this);
	m_body = world->CreateBody(&objBody);
}
//=============================================================================
void GameObject::setFixture(b2World* world, const sf::Vector2f& size)
{
	b2PolygonShape objShape;
	objShape.SetAsBox((size.x / 2.f) / SCALE, (size.y / 2.f) / SCALE);
	b2FixtureDef FixtureDef;
	FixtureDef.density = 1.5f;
	FixtureDef.friction = 0.7f;
	FixtureDef.shape = &objShape;
	m_body->CreateFixture(&FixtureDef);
}
//=============================================================================
sf::Vector2f GameObject::getPos() const
{
	return m_sprite.getPosition();
}
//=============================================================================
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//=============================================================================
bool GameObject::isRemoved() const
{
	if (m_removed)
	{
		m_body->GetWorld()->DestroyBody(m_body);
		return true;
	}
	return false;
}
//=============================================================================
void GameObject::removed()
{
	m_removed = true;
}
//=============================================================================