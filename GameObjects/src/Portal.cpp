//============================================================================
#include "Portal.h"
//============================================================================
bool Portal::m_registerit = Factory<StaticObject>::registerit("Portal",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<StaticObject>
	{ return std::make_unique<Portal>(world, bodyT, pos, rotation, size, gameObj); });
//============================================================================
Portal::Portal(b2World* world, int bodyT,
	const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
	:StaticObject(world, bodyT, pos, rotation, size, gameObj)
{
	b2PolygonShape shape;
	shape.SetAsBox((size.x / 2.f) / SCALE, (size.y / 2.f) / SCALE);
	setFixture(shape, 1.f, 1.f, 0.f, (uint16)CategoryBits::PortalSensor,
		(uint16)CategoryBits::Hero | (uint16)CategoryBits::FeetSensor | (uint16)CategoryBits::Dorothy, false);
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
	m_animation->addAnimation("Default", 100.f, Resources::instance().getAnimInfo((int)Animations::REDHEELS), size);
}
//============================================================================

//============================================================================