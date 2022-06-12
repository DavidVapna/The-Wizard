//=============================================================================
#include "MapData.h"
#include "Factory.h"
//=============================================================================
MapData::MapData()
    :m_numOfMaps(0), m_hero(0),m_moving(0),m_static(0)
{

}
//=============================================================================
void MapData::loadMap(int map)
{
    ++m_numOfMaps;
    std::string level("Level" + std::to_string(map) + ".ini");
    std::ifstream data(level);
    std::string streamLine;

    std::vector<Object> staticObjs, movingObjs;


    std::getline(data, streamLine);
    loadFromFile(data, streamLine, map, staticObjs, movingObjs);

    m_static.push_back(staticObjs);
    m_moving.push_back(movingObjs);

}
//=============================================================================
void MapData::loadFromFile(std::ifstream& data, std::string& string, int map,
    std::vector<Object>& staticObjs, std::vector<Object>& movingObjs)
{
    std::string streamLine;

    if (!data.is_open())
    {
        //throw
        return;
    }
    while (!data.eof())
    {
        setObjects(data, streamLine, map, staticObjs, movingObjs);
    }
    data.close();
}
//=============================================================================
void MapData::setObjects(std::ifstream& data, std::string& streamLine, int map,
    std::vector<Object>& staticObjs, std::vector<Object>& movingObjs)
{
    Object newObject;
    std::getline(data, streamLine);
    std::istringstream stringStream(streamLine);
    stringStream >> newObject.type;
    stringStream >> newObject.name;
    stringStream >> newObject.bodyType;
    stringStream >> newObject.startingPos.x >> newObject.startingPos.y;
    stringStream >> newObject.rotation;
    stringStream >> newObject.objectSize.x >> newObject.objectSize.y;
    stringStream >> newObject.textureEnum;

    if (newObject.type == "Hero")
    {
        m_hero.push_back(newObject);
    }
    else if (newObject.type == "Moving")
    {
        movingObjs.push_back(newObject);
    }
    else if(newObject.type == "Static")
    {
        staticObjs.push_back(newObject);
    }
}

//=============================================================================
std::unique_ptr<Hero> MapData::createHero(b2World& world, int currMap)
{
    return   Factory<Hero>::create(
        m_hero[currMap].name, &world, m_hero[currMap].bodyType,
        m_hero[currMap].startingPos, m_hero[currMap].rotation,
        m_hero[currMap].objectSize, m_hero[currMap].textureEnum);
}
//=============================================================================
std::unique_ptr<MovingObject> MapData::createMovingObject(int index, b2World& world, int currMap)
{
    return  Factory<MovingObject>::create(
        m_moving[currMap][index].name, &world, m_moving[currMap][index].bodyType,
        m_moving[currMap][index].startingPos, m_moving[currMap][index].rotation,
        m_moving[currMap][index].objectSize, m_moving[currMap][index].textureEnum
    );
}
//=============================================================================
std::unique_ptr<StaticObject> MapData::createStaticObject(int index, b2World& world, int currMap)
{
    return  Factory<StaticObject>::create(
        m_static[currMap][index].name, &world, m_static[currMap][index].bodyType,
        m_static[currMap][index].startingPos, m_static[currMap][index].rotation,
        m_static[currMap][index].objectSize, m_static[currMap][index].textureEnum
    );
}
//=============================================================================
int MapData::getStaticCount(int currMap)
{
    return m_static[currMap].size();
}
//=============================================================================
int MapData::getMovingCount(int currMap)
{
    return m_moving[currMap].size();
}
//=============================================================================
int MapData::getNumOfMaps()
{
    return m_numOfMaps;
}
//=============================================================================
std::string MapData::getCurrHero(int currMap)
{
    return m_hero[currMap].name;
}
//=============================================================================