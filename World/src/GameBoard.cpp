//=============================================================================
#include "GameBoard.h"

//=============================================================================
GameBoard::GameBoard(sf::RenderWindow* window, b2World* world)
    :m_window(window), m_world(world), m_mapIndex(0)
{

}
//=============================================================================
void GameBoard::loadGame()
{
    for (int index = 0; index < NUM_OF_MAPS; ++index)
    {
        m_maps.loadMap(index);
    }
    m_hero = std::move(m_maps.createHero(*m_world, m_mapIndex));

    for (int index = 0; index < m_maps.getStaticCount(m_mapIndex); index++)
    {
        m_staticObjects.push_back(std::move(m_maps.createStaticObject(index, *m_world, m_mapIndex)));
    }
    for (int index = 0; index < m_maps.getMovingCount(m_mapIndex); index++)
    {
        m_movingObjects.push_back(std::move(m_maps.createMovingObject(index, *m_world, m_mapIndex)));
    }
    for (int index = 0; index < m_maps.getNPCCount(m_mapIndex); index++)
    {
        m_npcObjects.push_back(std::move(m_maps.createNpcObject(index, *m_world, m_mapIndex)));
    }
}
//=============================================================================
void GameBoard::draw()
{
    for (auto& movingObj : m_movingObjects)
        movingObj->draw(*m_window);
    for (auto& staticObj : m_staticObjects)
        staticObj->draw(*m_window);
    for (auto& npc : m_npcObjects)
    {
        if (npc->inChat())
            npc->drawText(*m_window);
        npc->draw(*m_window);
    }

    m_hero->draw(*m_window);
}
//=============================================================================
void GameBoard::update(const float& deltaTime)
{
    m_hero->update(deltaTime);
    for (auto& movingObj : m_movingObjects)
        movingObj->update(deltaTime);
    for (auto& staticObj : m_staticObjects)
        staticObj->update(deltaTime);
    for (auto& npc : m_npcObjects)
    {
        npc->isClicked(*m_window);
        npc->update(deltaTime);
    }
    
    for (auto i = 0; i < m_staticObjects.size(); i++)
    {
        if (m_staticObjects[i]->isRemoved())
        {
            m_staticObjects.erase(m_staticObjects.begin() + i);
            i--;
        }
    }
    for (auto i = 0; i < m_movingObjects.size(); i++)
    {
        if (m_movingObjects[i]->isRemoved())
        {
            m_movingObjects.erase(m_movingObjects.begin() + i);
            i--;
        }
    }
}
//=============================================================================
sf::Vector2f GameBoard::getHeroPos()
{
    return m_hero->getPos();
}
//=============================================================================
void GameBoard::nextMap()
{
    m_window;
    m_staticObjects;
    m_npcObjects;
    m_movingObjects;


    m_hero->removed();
    for (auto& moving : m_movingObjects)
    {
        moving->removed();
    }
    for (auto& staticObj : m_staticObjects)
    {
        staticObj->removed();
    }
    ++m_mapIndex;
}
//=============================================================================