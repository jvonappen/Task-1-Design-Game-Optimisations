#pragma once
#include "GameMode.h"
#include "GameObject.h"

#include <vector>
#include <memory>

class TestMode : public GameMode
{
public:

	TestMode();

	void update(float delta) override;
	void draw() override;

	/* Create game object */
	GameObjectPtr createGameObject();
	void addGameObject(GameObjectPtr object);
	void removeGameObject(GameObjectPtr object);

private:
	std::vector<GameObjectPtr> m_gameObjects;
	std::vector<GameObjectPtr> m_removeGameObjects;
};

