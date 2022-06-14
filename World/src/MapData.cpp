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

    std::vector<ObjectInfo> staticObjs, movingObjs;


    std::getline(data, streamLine);
    loadFromFile(data, streamLine, map, staticObjs, movingObjs);

    m_static.push_back(staticObjs);
    m_moving.push_back(movingObjs);

    mapStringToInt();
}
//=============================================================================
void MapData::loadFromFile(std::ifstream& data, std::string& string, int map,
    std::vector<ObjectInfo>& staticObjs, std::vector<ObjectInfo>& movingObjs)
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
    std::vector<ObjectInfo>& staticObjs, std::vector<ObjectInfo>& movingObjs)
{
    ObjectInfo newObject;
    std::getline(data, streamLine);
    std::istringstream stringStream(streamLine);
    stringStream >> newObject.type;
    stringStream >> newObject.name;
    stringStream >> newObject.bodyType;
    stringStream >> newObject.startingPos.x >> newObject.startingPos.y;
    stringStream >> newObject.rotation;
    stringStream >> newObject.objectSize.x >> newObject.objectSize.y;

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
void MapData::mapStringToInt()
{
    m_stringTextures["Glinda"] = (int)Textures::Glinda;
    m_stringTextures["Dorothy"] = (int)Textures::Dorothy;
    m_stringTextures["Block"] = (int)Textures::Block;
    m_stringTextures["RedHeels"] = (int)Textures::RedHeels;
    m_stringTextures["Mouse"] = (int)Textures::Mouse;
}
//=============================================================================
std::unique_ptr<Hero> MapData::createHero(b2World& world, int currMap)
{
    return Factory<Hero>::create(&world, m_hero[currMap],
        m_stringTextures.find(m_hero[currMap].name)->second);

}
//=============================================================================
std::unique_ptr<MovingObject> MapData::createMovingObject(int index, b2World& world, int currMap)
{
    return  Factory<MovingObject>::create(&world, m_moving[currMap][index],
        m_stringTextures.find(m_moving[currMap][index].name)->second);
}
//=============================================================================
std::unique_ptr<StaticObject> MapData::createStaticObject(int index, b2World& world, int currMap)
{
    return  Factory<StaticObject>::create(&world, m_static[currMap][index],
        m_stringTextures.find(m_static[currMap][index].name)->second);
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

//=============================================================================