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
	
}
//=============================================================================

//=============================================================================