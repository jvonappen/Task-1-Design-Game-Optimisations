#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include <algorithm>
#include "Player.h"
#include "Collision.h"



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
	/*Collision check*/
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i]->hasComponent<Collision>())
		{
			auto colliderA = m_gameObjects[i]->getComponent<Collision>();
		}
	
	}

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

void PlayMode::removeGameObject(GameObjectPtr object)
{
	m_removeGameObjects.push_back(object);
}

