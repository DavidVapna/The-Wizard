//============================================================================
#include "MultiMethod.h"
#include "Hero.h"
#include "RedHeels.h"
#include "Block.h"
#include "Dorothy.h"
//============================================================================
using Key = std::pair<std::type_index, std::type_index>;
//============================================================================
MultiMethod::MultiMethod()
{
    m_collisionFuncs[Key(typeid(Dorothy), typeid(RedHeels))] = &MultiMethod::DorothyRedHeels;
    m_collisionFuncs[Key(typeid(RedHeels), typeid(Dorothy))] = &MultiMethod::redHeelsDorothy;
}
//============================================================================
void MultiMethod::DorothyRedHeels(GameObject* dorothy, GameObject* redHeels) const
{
    Dorothy* theHero = static_cast<Dorothy*>(dorothy);
    RedHeels* theRedHeels = static_cast<RedHeels*>(redHeels);
    if (!theHero || !theRedHeels)
    {
        //throw...
        std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
    }
    theRedHeels->removed();
}
//============================================================================
void MultiMethod::redHeelsDorothy(GameObject* redHeels, GameObject* dorothy) const
{
    DorothyRedHeels(dorothy, redHeels);
}
//============================================================================
//gets the reference for the singeltone collision map
MultiMethod& MultiMethod::getInstance() {
	static MultiMethod colision;
	return colision;
}
//============================================================================
//handles the collision between 2 objects
void MultiMethod::handleCollision(GameObject* objectA, GameObject* objectB)
{
	auto it = m_collisionFuncs.find(Key(typeid(*objectA), typeid(*objectB)));
	if (it != m_collisionFuncs.end())
		(this->*(it->second))(objectA, objectB);
}
//============================================================================