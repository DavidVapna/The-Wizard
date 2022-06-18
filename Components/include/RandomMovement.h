//=============================================================================
#pragma once
//=============================================================================
#include "Movement.h"
//=============================================================================
class RandomMovement : public Movement
{
public:
	RandomMovement(sf::Sprite* sprite, b2Body* body);
	void update(const float& deltaTime) override;
	void wallColided();

private:
	bool m_wallCollided;
	int m_stepsCounter;
};
//=============================================================================