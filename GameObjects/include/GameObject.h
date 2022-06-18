//=============================================================================
#pragma once
//=============================================================================
#include "Factory.h"
#include "Resources.h"
#include "Animation.h"
//=============================================================================
class GameObject
{
public:
	GameObject(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation,
		const sf::Vector2f& size, int gameObj);
	virtual ~GameObject() = default;

	virtual void draw(sf::RenderWindow& window);
	virtual bool isRemoved() const;
	virtual void removed();
	virtual sf::Vector2f getPos() const;
	virtual void update(const float& deltaTime) = 0;
	virtual void disable();

protected:
	//private functions
	void setBody(b2BodyDef& objBody, int bodyT, const sf::Vector2f& pos, bool rotation);
	void setFixture(b2PolygonShape& shape, float density, float friction, float restitution,
		uint16 categoryBits, uint16 maskBits, bool isSensor, int data = 0);


protected:
	sf::Sprite m_sprite;
	b2Body* m_body;
	bool m_colided;

	
	bool m_removed;
	std::unique_ptr<Animation> m_animation;

private:
};
//=============================================================================