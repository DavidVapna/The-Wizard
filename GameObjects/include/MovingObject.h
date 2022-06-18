//=============================================================================
#pragma once
//=============================================================================
#include "GameObject.h"
#include "Movement.h"
//=============================================================================
class MovingObject : public GameObject
{
public:
	MovingObject(b2World* world, int bodyT, const sf::Vector2f& pos,
		bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~MovingObject() = default;
	virtual void update(const float& deltaTime) override;
	void footContact(int val);

private:
	virtual void updateAnimation(const float& deltaTime);

protected:
	std::unique_ptr<Movement> m_moveComp;
	int m_numFootContacts;

private:
};
//=============================================================================