//=============================================================================
#pragma once 
//=============================================================================
//#include <memory>

#include "Macros.h"
//=============================================================================
template<class T>
class Factory
{
public:
	using pFnc = std::unique_ptr<T>(*)(b2World*, int, const sf::Vector2f&, bool, const sf::Vector2f& , int);

	static std::unique_ptr<T> create(b2World* world, ObjectInfo& info, int gameObj);

	static bool registerit(const std::string& name, pFnc);


private:
	static auto& getMap();
};
//=============================================================================
template<class T>
std::unique_ptr<T> Factory<T>::create(b2World* world, ObjectInfo& info, int gameObj)
{
	auto it = Factory::getMap().find(info.name);
	if (it == Factory::getMap().end())
		return nullptr;
	return it->second(world, info.bodyType, info.startingPos, info.rotation, info.objectSize, gameObj);
}
//=============================================================================
template<class T>
bool Factory<T>::registerit(const std::string& name, pFnc f) 
{
	Factory::getMap().emplace(name, f);
	return true;
}
//=============================================================================
template<class T>
auto& Factory<T>::getMap()
{
	static std::map<std::string, pFnc> map;
	return map;
}
//=============================================================================
/*
.name, &world, m_hero[currMap].bodyType,
		m_hero[currMap].startingPos, m_hero[currMap].rotation,
		m_hero[currMap].objectSize,
	   );
*/