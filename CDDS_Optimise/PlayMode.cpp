#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include <algorithm>
#include "Player.h"



PlayMode::PlayMode()
{
	auto player = createGameObject();
	player->setPosition(glm::vec2(200, 200));
	auto texture = Game::instance().resources().loadTexture("res/11.png");
	player->addComponent(new Sprite(texture));
	player->addComponent(new Player(*this));

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

void PlayMode::update(float delta)
{
	for (auto object : m_gameObjects)
	{
		object->update(delta);
	}
}

void PlayMode::draw()
{
	ClearBackground(GRAY);

	std::sort(m_gameObjects.begin(), m_gameObjects.end(), [](GameObjectPtr& a, GameObjectPtr& b)
	{
			return a->getPosition().y < b->getPosition().y;

	});

	for (auto object : m_gameObjects)
	{
		object->draw();
	}
}

GameObjectPtr PlayMode::createGameObject()
{
	auto object = std::make_shared<GameObject>();
	m_gameObjects.push_back(object);
	return object;
}

void PlayMode::addGameObject(GameObjectPtr object)
{
	m_gameObjects.push_back(object);
}