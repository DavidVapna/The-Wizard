//============================================================================
#pragma once
//============================================================================
#include "MovingObject.h"
//============================================================================
class Hero : public MovingObject
{
public:
	Hero(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~Hero() = default;
	virtual bool nextMap() const;
	void usedPortal();
	virtual void missionComplete();

private:
	float m_speed = 75.f;
	bool m_usedPortal;
	bool m_mission;
};
//============================================================================
