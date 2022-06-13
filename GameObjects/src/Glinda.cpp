//=============================================================================
#include "Glinda.h"
//=============================================================================
bool Glinda::m_registerit = Factory<StaticObject>::registerit("Glinda",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<StaticObject>
	{ return std::make_unique<Glinda>(world, bodyT, pos, rotation, size, gameObj); });
//=============================================================================
Glinda::Glinda(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:StaticObject(world, bodyT, pos, rotation, size, gameObj)
{
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//=============================================================================

//=============================================================================

//=============================================================================