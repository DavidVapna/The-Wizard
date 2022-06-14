//============================================================================
#pragma once
//============================================================================
#include "MultiMethod.h"
//============================================================================
class ContactListener : public b2ContactListener
{
public:
	virtual ~ContactListener() = default;
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);

private:
	void sendCollision(b2Body* contactA, b2Body* contactB);



};
//============================================================================