//=============================================================================
#pragma once
//=============================================================================
#include "GameObject.h"
//=============================================================================
class StaticObject : public GameObject
{
public:
	StaticObject(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	virtual void update(const float& deltaTime) override;
	void setAnimation(const sf::Vector2f& size, int theObject) override;


	StaticObject(StaticObject&&) = default;
	StaticObject& operator=(StaticObject&&) = default;

private:


};
//=============================================================================