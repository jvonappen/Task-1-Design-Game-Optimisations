#pragma once
#include "GameMode.h"
#include "GameObject.h"

#include <vector>
#include <memory>
#include <list>

class PlayMode : public GameMode
{
public:
	
	PlayMode();

	void update(float delta) override;
	void draw() override;

	/* Create game object */
	GameObjectPtr createGameObject();
	void addGameObject(GameObjectPtr object);
	void removeGameObject(GameObjectPtr object);

private:
	std::vector<GameObjectPtr> m_gameObjects;
	std::vector<GameObjectPtr> m_removeObjectsThisFrame;
	std::vector<GameObjectPtr> m_newObjectsThisFrame;
};

