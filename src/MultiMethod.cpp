//============================================================================
#include "MultiMethod.h"
#include "Hero.h"
#include "RedHeels.h"
#include "Block.h"
//============================================================================
using Key = std::pair<std::type_index, std::type_index>;
//============================================================================
MultiMethod::MultiMethod()
{
    m_collisionFuncs[Key(typeid(Hero), typeid(RedHeels))] = &MultiMethod::HeroRedHeels;
    m_collisionFuncs[Key(typeid(RedHeels), typeid(Hero))] = &MultiMethod::RedHeelsHero;
}
//============================================================================
void MultiMethod::HeroRedHeels(GameObject* hero, GameObject* redHeels) const
{
    // To get the actual types and use them:
    Hero* theHero = static_cast<Hero*>(hero);
    RedHeels* theRedHeels = static_cast<RedHeels*>(redHeels);
    if (!theHero || !theRedHeels)
    {
        //throw...
        std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
    }
    theRedHeels->removed();
}
//============================================================================
void MultiMethod::RedHeelsHero(GameObject* redHeels, GameObject* hero) const
{
    HeroRedHeels(hero, redHeels);
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