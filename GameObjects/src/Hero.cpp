//============================================================================
#include "Hero.h"
#include "PlayerMovement.h"
//============================================================================
Hero::Hero(b2World* world, int bodyT, const sf::Vector2f& pos,
	bool rotation, const sf::Vector2f& size, int gameObj)
	:MovingObject(world, bodyT, pos, rotation, size, gameObj),
	m_usedPortal(false), m_mission(false)
{
	m_moveComp = std::make_unique<PlayerMovement>(&m_sprite, m_body, &m_numFootContacts);
}
//============================================================================
bool Hero::nextMap() const
{
	return m_usedPortal; 
}
//============================================================================
void Hero::usedPortal()
{
	if (!m_mission)
		m_usedPortal = true;
}
//============================================================================
void Hero::missionComplete()
{
	m_mission = true; 
}
//============================================================================