//============================================================================
#pragma once
//============================================================================
#include "Direction.h"

//============================================================================
class MovementComponent
{
public:
	MovementComponent(sf::Sprite* sprite, b2Body* body);
	~MovementComponent();

	void move(const float& deltaTime);
	void jump(const float& deltaTime);
	void setDirection(Direction dir);
	void setIdle();
	Direction getDirection() const;


private:
	Direction m_direction;
	sf::Sprite* m_sprite;
	b2Body* m_body;
	float m_speed = 300.f;
};
//=============================================================================