#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include "Player.h"
#include "Collision.h"
#include "Menu.h"
#include "Movement.h"
#include "Collision.h"

#include <algorithm>
#include <raymath.h>


PlayMode::PlayMode()
{
	auto player = createGameObject();
	player->setPosition(glm::vec2(150, 150));
	auto texture = Game::instance().resources().loadTexture("res/11.png");
	player->addComponent(new Sprite(texture));
	player->addComponent(new Player(*this));

	auto critter = createGameObject();
	critter->setPosition(glm::vec2(300, 200));
	critter->SetVelocity(glm::vec2(80,80));
	auto critterTexture = Game::instance().resources().loadTexture("res/10.png");
	critter->addComponent(new Sprite(critterTexture));
	//critter->addComponent(new Collision(15));
	critter->addComponent(new Movement(80.0f));

	auto destroyerV2 = createGameObject();
	destroyerV2->setPosition(glm::vec2(250, 250));
	destroyerV2->SetVelocity(glm::vec2(80, 80));
	auto destroyerV2Texture = Game::instance().resources().loadTexture("res/9.png");
	destroyerV2->addComponent(new Sprite(destroyerV2Texture));
	destroyerV2->addComponent(new Movement(80.0f));

	const int CRITTER_COUNT = 50;
	for (int i = 0; i < CRITTER_COUNT; i++)
	{

		auto pos = glm::vec2{ GetRandomValue(0, GetScreenWidth()), GetRandomValue(0, GetScreenHeight()) };
		auto critterClone = critter->clone(pos);
		critterClone->SetVelocity(glm::vec2(80, 80));
		m_gameObjects.push_back(critterClone);
	}

	

}

void PlayMode::update(float delta)
{
	
	/*Collision check*/
	//for (int i = 0; i < m_gameObjects.size(); i++)
	//{
	//	if (m_gameObjects[i]->hasComponent<Collision>())				/*newly added*/
	//	{
	//		auto collisionA = m_gameObjects[i]->getComponent<Collision>();
	//		for (int j = i + 1; j < m_gameObjects.size(); j++)
	//		{
	//			if (m_gameObjects[j]->hasComponent<Collision>())
	//			{
	//				auto collisionB = m_gameObjects[j]->getComponent<Collision>();
	//				if (collisionA->checkCollision(*m_gameObjects[i], *m_gameObjects[j], *collisionB))
	//				{
	//					for (auto& pair : m_gameObjects[i]->components())
	//					{
	//						pair.second->onCollision(*m_gameObjects[i], *m_gameObjects[j]);
	//					}
	//					for (auto& pair : m_gameObjects[j]->components())
	//					{
	//						pair.second->onCollision(*m_gameObjects[j], *m_gameObjects[i]);
	//					}
	//				}
	//			}		
	//		}
	//	}
	//}
	//bool checkCollision(GameObject critter, GameObject & other, Collision & collider); /*newly added*/

	for (auto object : m_gameObjects)
	{
		object->update(delta);
	}
	for (auto object : m_newObjectsThisFrame)
	{
		m_gameObjects.push_back(object);
	}
	m_newObjectsThisFrame.clear();


	auto p = [&](auto& object) 
	{
		return std::find(
			m_removeObjectsThisFrame.begin(),
			m_removeObjectsThisFrame.end(),
			object) != m_removeObjectsThisFrame.end();
	};
	m_gameObjects.erase(std::remove_if(
		m_gameObjects.begin(),
		m_gameObjects.end(),
		p),
		m_gameObjects.end());
	
	m_removeObjectsThisFrame.clear();

}

void PlayMode::draw()
{
	ClearBackground(RAYWHITE);

	///*Adds the layered effect, where objects lower on the y axis are "infront" of other objects higher on the y axis*/
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
	m_newObjectsThisFrame.push_back(object);
	//m_gameObjects.push_back(object);
	return object;
}

void PlayMode::addGameObject(GameObjectPtr object)
{
	m_newObjectsThisFrame.push_back(object);
	//m_gameObjects.push_back(object);
}

void PlayMode::removeGameObject(GameObjectPtr object)
{
	m_removeObjectsThisFrame.push_back(object);
}

