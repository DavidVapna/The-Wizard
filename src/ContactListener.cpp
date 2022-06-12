//============================================================================
#include "ContactListener.h"

//============================================================================
void ContactListener::BeginContact(b2Contact* contact)
{
	auto contactA = contact->GetFixtureA()->GetBody();
	auto contactB = contact->GetFixtureB()->GetBody();
	sendCollision(contactA, contactB);
}
//============================================================================
void ContactListener::sendCollision(b2Body* contactA, b2Body* contactB)
{
	//GameObject* objectA = static_cast<GameObject*>(contactA->GetUserData());
	//GameObject* objectB = static_cast<GameObject*>(contactB->GetUserData());
	
	auto point = contactA->GetUserData().pointer;
	GameObject* objectA = reinterpret_cast<GameObject*>(contactA->GetUserData().pointer);
	GameObject* objectB = reinterpret_cast<GameObject*>(contactB->GetUserData().pointer);
	if (!objectA || !objectB)
		return;

	MultiMethod::getInstance().handleCollision(objectA, objectB);
}
//============================================================================
void ContactListener::EndContact(b2Contact* contact)
{

}
//============================================================================

//============================================================================





 