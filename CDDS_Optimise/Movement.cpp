#include "Movement.h"
#include "PlayMode.h"
//#include "raylib.h"
#include <glm/gtx/norm.hpp>
#include <glm/vec2.hpp>

#include <random>
#include <raymath.h>

Movement::Movement(PlayMode& mode) : m_mode(mode)
{

}

void Movement::update(GameObject& owner, float delta)
{

		float speed = 80;
		glm::vec2 velocity{ -100 + (rand() % 200), -100 + (rand() % 200) }; /*create a random direction vector for the velocity*/


		//direction = Vector2Scale(Vector2Normalize(direction), speed);
		velocity = glm::normalize(velocity);
		owner.setPosition(owner.getPosition() + velocity * speed * delta);

	


	if ()
	{
		velocity.x -= 1;		/* Left */
	}
	//if (IsKeyDown(KEY_D))
	//{
	//	direction.x += 1;		/* Right */
	//}
	//if (IsKeyDown(KEY_W))
	//{
	//	direction.y -= 1;		/* Up */
	//}
	//if (IsKeyDown(KEY_S))
	//{
	//	direction.y += 1;		/* Down */
	//}


}
