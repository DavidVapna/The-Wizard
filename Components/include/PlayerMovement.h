//=============================================================================
#pragma once
//=============================================================================
#include "Movement.h"
//=============================================================================
class PlayerMovement : public Movement
{
public:
	PlayerMovement(sf::Sprite* sprite, b2Body* body, int* numFootContacts);
	void update(const float& deltaTime) override;

private:
	int* m_numFootContacts;
	int m_jumpTimeout;
};
//=============================================================================