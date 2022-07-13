#include "Movement.h"
#include "PlayMode.h"
//#include "raylib.h"

#include <random>

Movement::Movement(PlayMode& mode) : m_mode(mode)
{

}

void Movement::update(GameObject& owner, float delta)
{
	glm::vec2 direction{ -100 + (rand() % 200), -100 + (rand() % 200) }; /*create a random direction vector for the velocity*/
	float speed = 80;
	owner.setPosition(owner.getPosition() + direction * speed * delta);
}
