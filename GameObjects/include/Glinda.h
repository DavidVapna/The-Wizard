//=============================================================================
#pragma once
//=============================================================================
#include "NPC.h"
//=============================================================================
class Glinda : public NPC
{
public:
	Glinda(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);

private:

	static bool m_registerit;
};
//=============================================================================