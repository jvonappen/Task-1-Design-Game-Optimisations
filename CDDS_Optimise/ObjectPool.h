#pragma once
#include <vector>
#include "GameObject.h"

class PlayMode;

class ObjectPool
{
public:
	ObjectPool(PlayMode& mode, GameObjectPtr prototype, int cap);

	GameObjectPtr spawn();
	void despawn(GameObjectPtr object);

private:
	std::vector<GameObjectPtr>m_inactive;
	PlayMode& m_mode;
	GameObjectPtr m_prototype;
};

