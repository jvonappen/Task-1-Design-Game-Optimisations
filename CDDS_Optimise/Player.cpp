#include "Player.h"
#include "PlayMode.h"
#include "raylib.h"

Player::Player(PlayMode& mode) : m_mode(mode)
{

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

	owner.setPosition(owner.getPosition() + direction * speed * delta);
}
