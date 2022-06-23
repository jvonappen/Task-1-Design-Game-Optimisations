#pragma once
#include <vector>
#include "GameObject.h"

class PlayMode;
//class TestMode;

class ObjectPool
{
public:
	ObjectPool(PlayMode& mode, GameObjectPtr prototype, int cap);
	GameObjectPtr spawn();
	void despawn(GameObjectPtr object);
	void clean();

private:
	std::vector<GameObjectPtr>m_inactive;
	std::vector<GameObjectPtr>m_active;
	PlayMode& m_mode;
	GameObjectPtr m_prototype;
};

//class ObjectPoolTM
//{
//public:
//	ObjectPoolTM(TestMode& mode, GameObjectPtr prototype, int cap);
//	GameObjectPtr spawn();
//	void despawn(GameObjectPtr object);
//	void clean();
//
//private:
//	std::vector<GameObjectPtr>m_inactive;
//	std::vector<GameObjectPtr>m_active;
//	TestMode& m_mode;
//	GameObjectPtr m_prototype;
//};