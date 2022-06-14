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
	GameObject(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~GameObject() = default;

	virtual void setAnimation(const sf::Vector2f& size, int theObject) = 0;


	virtual void draw(sf::RenderWindow& window);
	virtual bool isRemoved() const;
	virtual void removed();
	virtual sf::Vector2f getPos() const;

	//Pure Virtual
	virtual void update(const float& deltaTime) = 0;
	virtual void disable();

protected:
	//private functions
	void setBody(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation);
	void setFixture(b2World* world, const sf::Vector2f& size, uint16 categoryBits = 1, bool isSensor = 0, uint16 maskBits = 1);

protected:
	sf::Sprite m_sprite;
	b2Body* m_body;
	bool m_colided;

	
	bool m_removed;
	std::unique_ptr<Animation> m_animation;

private:
};
//=============================================================================