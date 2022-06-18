//=============================================================================
#include "GameObject.h"
//=============================================================================
GameObject::GameObject(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:m_colided(false), m_removed(false)
{
	b2BodyDef bodyDef;
	setBody(bodyDef, bodyT, pos, rotation);
	m_body = world->CreateBody(&bodyDef);
	m_sprite.setTexture(Resources::instance().getTexture(gameObj));
	m_animation = std::make_unique<Animation>(m_sprite);
}
//=============================================================================
void GameObject::setBody(b2BodyDef& objBody, int bodyT, const sf::Vector2f& pos, bool rotation)
{
	objBody.position.Set(pos.x / SCALE , pos.y / SCALE);
	objBody.type = (b2BodyType)bodyT;
	objBody.angle = 0;
	objBody.fixedRotation = rotation;
}
//=============================================================================
void GameObject::setFixture(b2PolygonShape& shape, float density, float friction,
	float restitution, uint16 categoryBits, uint16 maskBits, bool isSensor, int data)
{
	b2FixtureDef fixtureDef;
	fixtureDef.shape = &shape;
	fixtureDef.density = density;
	fixtureDef.friction = friction;
	fixtureDef.restitution = restitution;
	fixtureDef.filter.categoryBits = categoryBits;
	fixtureDef.filter.maskBits = maskBits;
	fixtureDef.isSensor = isSensor;
	fixtureDef.userData.pointer = data;
	m_body->CreateFixture(&fixtureDef);
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
void GameObject::disable()
{
	m_body->SetEnabled(false);
}
//=============================================================================