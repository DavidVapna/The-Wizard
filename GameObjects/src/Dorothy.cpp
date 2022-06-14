//=============================================================================
#include "Dorothy.h"
//=============================================================================
bool Dorothy::m_registerit = Factory<Hero>::registerit("Dorothy",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<Hero>
	{ return std::make_unique<Dorothy>(world, bodyT, pos, rotation, size, gameObj); });
//=============================================================================
Dorothy::Dorothy(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:Hero(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);


	//b2Filter filter;
	//filter.categoryBits = (uint16)CategoryBits::Hero;
	//filter.maskBits = (uint16)CategoryBits::Glinda | (uint16)CategoryBits::Boundries | (uint16)CategoryBits::Hero;
	//m_body->GetFixtureList()->SetFilterData(filter);
}
//=============================================================================

//=============================================================================