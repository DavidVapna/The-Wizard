//============================================================================
#include "MultiMethod.h"
#include "Hero.h"
#include "RedHeels.h"
#include "Block.h"
#include "Dorothy.h"
#include "RandomEnemy.h"
#include "Glinda.h"
//============================================================================
using Key = std::pair<std::type_index, std::type_index>;
//============================================================================
MultiMethod::MultiMethod()
{
    m_collisionFuncs[Key(typeid(Dorothy ), typeid(RedHeels))] = &MultiMethod::DorothyRedHeels;
    m_collisionFuncs[Key(typeid(RedHeels), typeid(Dorothy ))] = &MultiMethod::redHeelsDorothy;

    m_collisionFuncs[Key(typeid(RandomEnemy), typeid(Block   ))] = &MultiMethod::RandomEnemyBlock;
    m_collisionFuncs[Key(typeid(Block   ), typeid(RandomEnemy))] = &MultiMethod::BlockRandomEnemy;

    m_collisionFuncs[Key(typeid(Dorothy   ), typeid(Glinda))] = &MultiMethod::HeroGlinda;
    m_collisionFuncs[Key(typeid(Glinda ), typeid(Dorothy))] = &MultiMethod::GlindaHero;

    m_collisionFuncs[Key(typeid(Dorothy), typeid(Block))] = &MultiMethod::blockHero;

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
void MultiMethod::HeroGlinda(GameObject* hero, GameObject* glinda) const
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Dorothy* theHero = static_cast<Dorothy*>(hero);
        Glinda* theGlinda = static_cast<Glinda*>(glinda);
        if (!theHero || !glinda)
        {
            //throw...
            std::cout << "baddd" << "HERO RED HEELS MULTIMETHOD SETT THROW!!!";
        }
        theGlinda->chat();
    }
}
//============================================================================
void MultiMethod::GlindaHero(GameObject* glinda, GameObject* hero) const
{
    HeroGlinda(hero, glinda);
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
//gets the reference for the singeltone collision map
MultiMethod& MultiMethod::getInstance() 
{
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
void legsGround(GameObject* legs, GameObject* ground)
{

}
//============================================================================
void groundLegs(GameObject* ground, GameObject* legs)
{

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