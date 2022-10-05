#include "Movement.h"
#include "raylib.h"

Movement::Movement(float speed) : m_speed(speed)
{

}

void Movement::update(GameObject& owner, float delta)
{

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
