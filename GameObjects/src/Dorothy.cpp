//=============================================================================
#include "Dorothy.h"
//=============================================================================
bool Dorothy::m_registerit = Factory<Hero>::registerit("Dorothy",
	[](b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj) ->
	std::unique_ptr<Hero>
	{ return std::make_unique<Dorothy>(world, bodyT, pos, rotation, size, gameObj); });
//=============================================================================
Dorothy::Dorothy(b2World* world, int bodyT, const sf::Vector2f& pos,
				 bool rotation, const sf::Vector2f& size, int gameObj)
	:Hero(world, bodyT, pos, rotation, size, gameObj)
{
	b2PolygonShape shape;
	shape.SetAsBox((size.x / 2.f) / SCALE, (size.y / 2.f) / SCALE);
	setFixture(shape, 1.5f, 1.f, 0.f, (uint16)CategoryBits::Hero 
					  | (uint16)CategoryBits::Dorothy, 0xFFFF, false);
	m_body->GetUserData().pointer = reinterpret_cast<uintptr_t>(this);
	
	m_animation->addAnimation("IdleL", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_IDLE_L), size);
	m_animation->addAnimation("IdleR", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_IDLE_R), size);
	m_animation->addAnimation("WalkL", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_WALK_L), size);
	m_animation->addAnimation("WalkR", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_WALK_R), size);
	m_animation->addAnimation("JumpL", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_JUMP_L), size);
	m_animation->addAnimation("JumpR", 100.f, Resources::instance().getAnimInfo((int)Animations::DOROTHY_JUMP_R), size);
}
//=============================================================================