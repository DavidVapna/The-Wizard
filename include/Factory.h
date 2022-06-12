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
	static std::unique_ptr<T> create(const std::string& name, b2World* world, int bodyT,
		const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj);
	static bool registerit(const std::string& name, pFnc);


private:
	static auto& getMap();
};
//=============================================================================
template<class T>
std::unique_ptr<T> Factory<T>::create(const std::string& name, b2World* world, int bodyT,
	const sf::Vector2f& pos, bool rotation, const sf::Vector2f& size, int gameObj)
{
	auto it = Factory::getMap().find(name);
	if (it == Factory::getMap().end())
		return nullptr;
	return it->second(world, bodyT, pos, rotation, size, gameObj);
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
std::vector<std::string> getNames() 
{
	std::vector<std::string> names;
	std::cout << "enter type of objects to build (or exit)" << std::endl;
	while (true) {
		std::string s;
		std::cin >> s;
		if (s == "exit")
			break;
		names.emplace_back(s);
	}
	return names;
}
auto inNames = getNames();
	for (const auto& name : inNames) 
	{
		auto p = Factory::create(name);

		if (p)
			p->show();
		else
			std::cout << "Class not found!\n";
	}	
*/