//============================================================================
#pragma once
//============================================================================
#include "StaticObject.h"
//============================================================================
class Portal : public StaticObject
{
public:
	Portal(b2World* world, int bodyT, const sf::Vector2f& pos,
		   bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~Portal() = default;

private:
	static bool m_registerit;
};
//============================================================================