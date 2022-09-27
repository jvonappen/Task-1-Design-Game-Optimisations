#include "Player.h"
#include "PlayMode.h"
#include "raylib.h"
#include "Game.h"
#include "Sprite.h"
#include "MakeInactive.h"
#include "Movement.h"

Player::Player(PlayMode& mode) : m_mode(mode)
{
	m_redCritterPrefab = std::make_shared<GameObject>();
	m_redCritterPrefab->addComponent(new Sprite(Game::instance().resources().loadTexture("res/12.png")));
	m_redCritterPrefab->addComponent(new MakeInactive(60.0f)); // increased time to allow for all 1500 critters to be on screen before becoming inactive since setting fps to 60. 
	m_redCritterPrefab->addComponent(new Movement(80.0f));
	
	m_redCritterPool = std::make_unique<ObjectPool>(mode, m_redCritterPrefab, 1500);
}

void Player::update(GameObject& owner, float delta)
{
	glm::vec2 direction{ 0,0 };
	float speed = 80;

	if (IsKeyDown(KEY_A))
	{
		direction.x -= 1;		/* Left */
	}
	if (IsKeyDown(KEY_D))
	{
		direction.x += 1;		/* Right */
	}
	if (IsKeyDown(KEY_W))
	{
		direction.y -= 1;		/* Up */
	}
	if (IsKeyDown(KEY_S))
	{
		direction.y += 1;		/* Down */
	}

	/*Additional Critter Spawn*/
	if (IsKeyDown(KEY_SPACE))
	{
		auto redCritter = m_redCritterPool->spawn();
		if (redCritter)
		{
			redCritter->getComponent<MakeInactive>()->resetTime();
			
			redCritter->setPosition(owner.getPosition());
			redCritter->SetVelocity(glm::vec2(GetRandomValue(30,80), 80));
			m_mode.addGameObject(redCritter);
		}
	}

	owner.setPosition(owner.getPosition() + direction * speed * delta);
	m_redCritterPool->clean();
}
