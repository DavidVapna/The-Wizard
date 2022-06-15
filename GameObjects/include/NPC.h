//============================================================================
#pragma once
//============================================================================
#include "StaticObject.h"
class Dorothy;
//============================================================================
class NPC : public StaticObject
{
public:

	NPC(b2World* world, int bodyT, const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	virtual ~NPC() = default;
	void setAnimation(const sf::Vector2f& size, int theObject);
	void update(const float& deltaTime);
	void chat(Dorothy* dorothy);


protected:
	sf::Text text;

private:
};
//============================================================================
