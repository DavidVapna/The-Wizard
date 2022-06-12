//=============================================================================
#pragma once
//=============================================================================
#include "MapData.h"
//=============================================================================
class GameBoard
{
public:
	GameBoard(sf::RenderWindow* window, b2World* world);
	~GameBoard() = default;

	void loadGame();
	void setLevels();
	void addObject();
	void draw();
	void update(const float& deltaTime);
	void nextMap();


	sf::Vector2f getHeroPos();


private:
	std::unique_ptr<Hero> m_hero;
	std::vector <std::unique_ptr<MovingObject>> m_movingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;
	b2World* m_world;
	sf::RenderWindow* m_window;
	int m_mapIndex;
	MapData m_maps;
};
//=============================================================================