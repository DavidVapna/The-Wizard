//============================================================================
#pragma once
//============================================================================
#include"Hero.h"
//============================================================================
using Key = std::pair< std::type_index, std::type_index>;
//============================================================================
template<class T>
struct ArgsHash
{
	std::size_t operator () (const std::pair<T, T>& p) const 
	{
		std::size_t h1 = std::hash<T>()(p.first);
		std::size_t h2 = std::hash<T>()(p.second);
		return h1 ^ h2;
	}
};
//============================================================================
template < class T>
struct KeyEqual
{
	bool operator()(const std::pair<T, T>& a1, const std::pair<T, T>& a2) const
	{
		return (a1.first == a2.first && a1.second == a2.second);
	}
};
//============================================================================
class MultiMethod
{
public:
	using CorrectFunc = void(MultiMethod::*)(GameObject* objectA, GameObject* objectB) const;
	static MultiMethod& getInstance();
	void handleCollision(GameObject* objectA, GameObject* objectB);

private:
	MultiMethod();
	MultiMethod(const MultiMethod&) = default;
	MultiMethod& operator=(const MultiMethod&) = default;

	void redHeelsDorothy(GameObject* redHeels, GameObject* dorothy) const;
	void DorothyRedHeels(GameObject* dorothy, GameObject* redHeels) const;
	void RandomEnemyBlock(GameObject* enemy, GameObject* block) const;
	void BlockRandomEnemy(GameObject* block, GameObject* enemy) const;
	void blockHero(GameObject* block, GameObject* hero) const;
	void HeroPortal(GameObject* hero, GameObject* portal) const;
	void PortalHero(GameObject* portal, GameObject* hero) const;
	
private:
	std::unordered_map<Key, CorrectFunc, ArgsHash<std::type_index>, KeyEqual<std::type_index>> m_collisionFuncs;
};
//============================================================================