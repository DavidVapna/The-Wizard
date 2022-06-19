//=============================================================================
#pragma once
//=============================================================================
#include "NPC.h"
#include "Hero.h"
//=============================================================================
class MapData
{
public:
	MapData();
	~MapData() = default;
	void loadGame(int map);


	int getStaticCount(int currMap) const;
	int getMovingCount(int currMap) const;
	int getNPCCount(int currMap) const;
	int getNumOfMaps();
	std::string getCurrHero(int currMap);
	void mapStringToInt();

	std::unique_ptr<Hero> createHero(b2World& world, int currMap);
	std::unique_ptr<MovingObject> createMovingObject(int index, b2World& world, int currMap);
	std::unique_ptr<StaticObject> createStaticObject(int index, b2World& world, int currMap);
	std::unique_ptr<NPC> createNpcObject(int index, b2World& world, int currMap);


private:
	void loadFromFile(std::ifstream& data, std::string& streamLine, int map,
		std::vector<ObjectInfo>& staticObjs, std::vector<ObjectInfo>& movingObjs,
		std::vector<ObjectInfo>& npcObjs);
	void setObjects(std::ifstream& data, std::string& streamLine, int map,
		std::vector<ObjectInfo>& staticObjs, std::vector<ObjectInfo>& movingObjs,
		std::vector<ObjectInfo>&npcObjs);
	
private:


	int m_numOfMaps;
	std::vector<ObjectInfo> m_hero;
	std::vector<std::vector<ObjectInfo>> m_moving;
	std::vector<std::vector<ObjectInfo>> m_static;
	std::vector<std::vector<ObjectInfo>> m_NPC;
	std::unordered_map<std::string, int> m_stringTextures;
};
//=============================================================================