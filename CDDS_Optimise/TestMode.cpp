#include "TestMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include <algorithm>
#include "Player.h"
#include "Collision.h"

TestMode::TestMode()
{
	auto critterV2 = createGameObject();
	critterV2->setPosition(glm::vec2(300, 200));
	auto critterTexture = Game::instance().resources().loadTexture("res/10.png");
	critterV2->addComponent(new Sprite(critterTexture));

	const int CRITTER_COUNT = 50;
	for (int i = 0; i < CRITTER_COUNT; i++)
	{
		auto pos = glm::vec2{ GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()) };
		auto critterClone = critterV2->clone(pos);
		m_gameObjects.push_back(critterClone);
	}
}

void TestMode::update(float delta)
{

	for (auto object : m_gameObjects)
	{
		object->update(delta);
	}

	auto pred = [&](auto& object)
	{
		return std::find(
			m_removeGameObjects.begin(),
			m_removeGameObjects.end(),
			object) != m_removeGameObjects.end();
	};

	m_gameObjects.erase(std::remove_if(m_gameObjects.begin(),
		m_gameObjects.end(), pred), m_gameObjects.end());

	m_removeGameObjects.clear();
}

void TestMode::draw()
{
	ClearBackground(RAYWHITE);

	std::sort(m_gameObjects.begin(), m_gameObjects.end(), [](GameObjectPtr& a, GameObjectPtr& b)
		{
			return a->getPosition().y < b->getPosition().y;

		});

	for (auto object : m_gameObjects)
	{
		object->draw();
	}
}

GameObjectPtr TestMode::createGameObject()
{
	auto object = std::make_shared<GameObject>();
	m_gameObjects.push_back(object);
	return object;
}

void TestMode::addGameObject(GameObjectPtr object)
{
	m_gameObjects.push_back(object);
}

void TestMode::removeGameObject(GameObjectPtr object)
{
	m_removeGameObjects.push_back(object);
}
