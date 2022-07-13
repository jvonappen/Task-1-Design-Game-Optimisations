#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include <algorithm>
#include "Player.h"
#include "Collision.h"
#include "Menu.h"
#include <raymath.h>
#include "Movement.h"


PlayMode::PlayMode()
{
	auto player = createGameObject();
	player->setPosition(glm::vec2(150, 150));
	auto texture = Game::instance().resources().loadTexture("res/11.png");
	player->addComponent(new Sprite(texture));
	player->addComponent(new Player(*this));

	auto critter = createGameObject();
	critter->setPosition(glm::vec2(300, 200));
	auto critterTexture = Game::instance().resources().loadTexture("res/10.png");
	critter->addComponent(new Sprite(critterTexture));
	critter->addComponent(new Collision(20));
	critter->addComponent(new Movement(*this));

	auto destroyerV2 = createGameObject();
	destroyerV2->setPosition(glm::vec2(250, 250));
	auto destroyerV2Texture = Game::instance().resources().loadTexture("res/9.png");
	destroyerV2->addComponent(new Sprite(destroyerV2Texture));

	const int CRITTER_COUNT = 50;
	for (int i = 0; i < CRITTER_COUNT; i++)
	{

		auto pos = glm::vec2{ GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()) };
		auto critterClone = critter->clone(pos);
		m_gameObjects.push_back(critterClone);
	}

	

}

void PlayMode::update(float delta)
{
	
	/*Collision check*/
	for (int i = 0; i < m_gameObjects.size(); i++)
	{
		if (m_gameObjects[i]->hasComponent("Collision"))				/*newly added*/
		{
			auto colliderA = m_gameObjects[i]->getComponent("Collision");
			for (int j = i + 1; j < m_gameObjects.size(); j++)
			{
				auto colliderB = m_gameObjects[j]->getComponent("Collision");
			}
		}
	
	}
	bool checkCollision(GameObject critter, GameObject & other, Collision & collider); /*newly added*/

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

