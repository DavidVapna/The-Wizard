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
	b2PolygonShape shape;
	shape.SetAsBox((size.x / 2.f) / SCALE, (size.y / 2.f) / SCALE);
	setFixture(shape, 1.f, 1.f, 0.f, (uint16)CategoryBits::Glinda,
		(uint16)CategoryBits::Boundries | (uint16)CategoryBits::Block,
		false);

	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
}
//=============================================================================

//=============================================================================

//=============================================================================