//============================================================================
#include "RedHeels.h"
//============================================================================
bool RedHeels::m_registerit = Factory<StaticObject>::registerit("RedHeels",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<StaticObject>
	{ return std::make_unique<RedHeels>(world, bodyT, pos, rotation, size, gameObj); });
//============================================================================
RedHeels::RedHeels(b2World* world, int bodyT, 
	const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:StaticObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//============================================================================

//============================================================================