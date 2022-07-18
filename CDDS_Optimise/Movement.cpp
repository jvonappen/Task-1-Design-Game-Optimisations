#include "Movement.h"
#include "raylib.h"

Movement::Movement(float speed) : m_speed(speed)
{

}

void Movement::update(GameObject& owner, float delta)
{

	//const int MAX_VELOCITY = m_speed;
	//owner.setPosition(owner.getPosition() + glm::vec2(0, delta * -m_speed));

	if (owner.getPosition().x < 0)
	{
		owner.setPosition(owner.getPosition());
		owner.SetVelocity(glm::vec2(-owner.GetVelocity().x, owner.GetVelocity().y));
	}
	if (owner.getPosition().x > GetScreenWidth())
	{
		owner.setPosition(owner.getPosition());
		owner.SetVelocity(glm::vec2(-owner.GetVelocity().x, owner.GetVelocity().y));
	}
	/*------------------------------*/
	if (owner.getPosition().y < 0)
	{
		owner.setPosition(owner.getPosition());
		owner.SetVelocity(glm::vec2(owner.GetVelocity().x, -owner.GetVelocity().y));
	}
	if (owner.getPosition().y > GetScreenHeight())
	{
		owner.setPosition(owner.getPosition());
		owner.SetVelocity(glm::vec2(owner.GetVelocity().x, -owner.GetVelocity().y));
	}
}
