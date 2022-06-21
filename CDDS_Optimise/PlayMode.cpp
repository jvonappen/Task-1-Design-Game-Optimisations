#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"



PlayMode::PlayMode()
{
	auto player = createGameObject();
	player->setPosition(glm::vec2(200, 200));
	auto texture = Game::instance().resources().loadTexture("res/11.png");
	player->addComponent(new Sprite(texture));

	auto critterV2 = createGameObject();
	critterV2->setPosition(glm::vec2(300, 200));
	auto critterTexture = Game::instance().resources().loadTexture("res/10.png");
	critterV2->addComponent(new Sprite(critterTexture));
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
