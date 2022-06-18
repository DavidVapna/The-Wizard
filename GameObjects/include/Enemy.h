//=============================================================================
#pragma once
//=============================================================================
#include "MovingObject.h"
//=============================================================================
class Enemy : public MovingObject
{
public:
	Enemy(b2World* world, int bodyT, const sf::Vector2f& pos,
		  bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~Enemy() = default;

private:
};
//=============================================================================