//=============================================================================
#pragma once
//=============================================================================
#include "Enemy.h"
//=============================================================================
class RandomEnemy : public Enemy
{
public:

	RandomEnemy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	void changeDirection();


private:
	static bool m_registerit;
};
//=============================================================================