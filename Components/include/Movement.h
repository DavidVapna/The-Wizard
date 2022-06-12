//============================================================================
#pragma once
//============================================================================
#include "Direction.h"
//============================================================================
class Movement
{
public:
	Movement(sf::Sprite* sprite, b2Body* body);
	virtual ~Movement() = default;
	
	virtual void update(const float& deltaTime) = 0;
	virtual void move(const float& deltaTime);
	void jump(const float& deltaTime);
	void setDirection(Direction dir);
	void setIdle();
	Direction getDirection() const;

protected:
	Direction m_direction;
private:
	sf::Sprite* m_sprite;
	b2Body* m_body;
	float m_speed = 300.f;
};
//=============================================================================