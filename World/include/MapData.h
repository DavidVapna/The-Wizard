//=============================================================================
#pragma once
//=============================================================================
#include "Block.h"
#include "RedHeels.h"
#include "Hero.h"
#include "Dorothy.h"
//=============================================================================
struct Object 
{
	std::string type, name, textureEnum;
	int bodyType;
	sf::Vector2f startingPos, objectSize;
	bool rotation;
};
//=============================================================================
class MapData
{
public:
	MapData();
	~MapData() = default;
	void loadMap(int map);


	int getStaticCount(int currMap);
	int getMovingCount(int currMap);
	int getNumOfMaps();
	std::string getCurrHero(int currMap);
	void mapStringToInt();

	std::unique_ptr<Hero> createHero(b2World& world, int currMap);
	std::unique_ptr<MovingObject> createMovingObject(int index, b2World& world, int currMap);
	std::unique_ptr<StaticObject> createStaticObject(int index, b2World& world, int currMap);


private:
	void loadFromFile(std::ifstream& data, std::string& string, int map,
		std::vector<Object>& staticObjs, std::vector<Object>& movingObjs);
	void setObjects(std::ifstream& data, std::string& streamLine, int map,
		std::vector<Object>& staticObjs, std::vector<Object>& movingObjs);
	
private:


	int m_numOfMaps;
	std::vector<Object> m_hero;
	std::vector<std::vector<Object>> m_moving;
	std::vector<std::vector<Object>> m_static;
	std::unordered_map<std::string, int> m_stringTextures;
};
