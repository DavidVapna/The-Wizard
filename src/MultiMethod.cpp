//============================================================================
#include "MultiMethod.h"
#include "Hero.h"
#include "RedHeels.h"
#include "Block.h"
#include "Dorothy.h"
#include "RandomEnemy.h"
#include "Glinda.h"
#include "Portal.h"
//============================================================================
using Key = std::pair<std::type_index, std::type_index>;
//============================================================================
MultiMethod::MultiMethod()
{
    m_collisionFuncs[Key(typeid(Dorothy ), typeid(RedHeels))] = &MultiMethod::DorothyRedHeels;
    m_collisionFuncs[Key(typeid(RedHeels), typeid(Dorothy ))] = &MultiMethod::redHeelsDorothy;
    m_collisionFuncs[Key(typeid(RandomEnemy), typeid(Block   ))] = &MultiMethod::RandomEnemyBlock;
    m_collisionFuncs[Key(typeid(Block   ), typeid(RandomEnemy))] = &MultiMethod::BlockRandomEnemy;
    m_collisionFuncs[Key(typeid(Dorothy), typeid(Block))] = &MultiMethod::blockHero;
    m_collisionFuncs[Key(typeid(Hero), typeid(Portal))] = &MultiMethod::HeroPortal;
    m_collisionFuncs[Key(typeid(Dorothy), typeid(Portal))] = &MultiMethod::HeroPortal;
    m_collisionFuncs[Key(typeid(Portal), typeid(Hero))] = &MultiMethod::PortalHero;
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
    theHero->missionComplete();
}
//============================================================================
void MultiMethod::redHeelsDorothy(GameObject* redHeels, GameObject* dorothy) const
{
    DorothyRedHeels(dorothy, redHeels);
}
//============================================================================
void MultiMethod::RandomEnemyBlock(GameObject* enemy, GameObject* block) const
{
    RandomEnemy* theEnemy = static_cast<RandomEnemy*>(enemy);
    Block* theBlock = static_cast<Block*>(block);
    if (!theEnemy || !theBlock)
    {
        //throw...
        std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
    }
    theEnemy->changeDirection();
}
//============================================================================
void MultiMethod::BlockRandomEnemy(GameObject* block, GameObject* enemy) const
{
    RandomEnemyBlock(enemy, block);
}
//============================================================================
MultiMethod& MultiMethod::getInstance() 
{
	static MultiMethod colision;
	return colision;
}
//============================================================================
void MultiMethod::handleCollision(GameObject* objectA, GameObject* objectB)
{
	auto it = m_collisionFuncs.find(Key(typeid(*objectA), typeid(*objectB)));
	if (it != m_collisionFuncs.end())
		(this->*(it->second))(objectA, objectB);
}
//============================================================================
void MultiMethod::HeroPortal(GameObject* hero, GameObject* portal) const
{
    Hero* theHero = static_cast<Hero*>(hero);
    Portal* thePortal = static_cast<Portal*>(portal);
    if (!theHero || !thePortal)
    {
        //throw...
        std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
    }
    theHero->usedPortal();
}
//============================================================================
void MultiMethod::PortalHero(GameObject* portal, GameObject* hero) const
{
    HeroPortal(hero, portal);
}
//============================================================================
void MultiMethod::blockHero(GameObject* block, GameObject* hero) const
{
    Block* theEnemy = static_cast<Block*>(block);
    Dorothy* theBlock = static_cast<Dorothy*>(hero);
    if (!theEnemy || !theBlock)
    {
        //throw...
        std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
    }
    std::cout << "hey";
}
//============================================================================