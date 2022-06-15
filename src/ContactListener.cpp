//============================================================================
#include "ContactListener.h"
//============================================================================
void ContactListener::BeginContact(b2Contact* contact)
{
    auto contactA = contact->GetFixtureA()->GetBody();
    auto contactB = contact->GetFixtureB()->GetBody();
    int fixDataA = contact->GetFixtureA()->GetUserData().pointer;
    int fixDataB = contact->GetFixtureB()->GetUserData().pointer;
    if (checkFootContact(fixDataA, 1, contactA) || checkFootContact(fixDataB, 1, contactB))
        return;

	sendCollision(contactA, contactB);
}
//============================================================================
bool ContactListener::checkFootContact(int fixtureUserData, int val, b2Body* body)
{
    if (fixtureUserData == 3)
    {
        MovingObject* hero = reinterpret_cast<MovingObject*>(body->GetUserData().pointer);
        hero->footContact(val);
        m_footContact += val;
        return true;
    }
    return false;
}
//============================================================================
void ContactListener::sendCollision(b2Body* contactA, b2Body* contactB)
{	
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
    auto contactA = contact->GetFixtureA()->GetBody();
    auto contactB = contact->GetFixtureB()->GetBody();
    int fixDataA = contact->GetFixtureA()->GetUserData().pointer;
    int fixDataB = contact->GetFixtureB()->GetUserData().pointer;
    if (checkFootContact(fixDataA, -1, contactA) ||
        checkFootContact(fixDataB, -1, contactB))
        return;
}
//============================================================================

//============================================================================





 