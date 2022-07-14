#pragma once
#include "GameObject.h"
#include "ObjectPool.h"

class PlayMode;

class Player : public Component
{
public:
	Player(PlayMode& mode);

	void update(GameObject& owner, float delta) override;

	const char* getName() override { return "Player"; }
	Component* clone() override 
	{
		return nullptr;
	}

private:
	PlayMode& m_mode;
	GameObjectPtr m_redCritterPrefab;
	std::unique_ptr<ObjectPool> m_redCritterPool;
};

