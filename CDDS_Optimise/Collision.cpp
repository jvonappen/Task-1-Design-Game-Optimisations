#include "Collision.h"
#include "raylib.h"
#include <glm/gtx/norm.hpp>

Collision::Collision(float radius) : m_radius(radius)
{

}

bool Collision::checkCollision(GameObject& owner, GameObject& other, Collision& collision)
{
    float r2 = m_radius + collision.m_radius;        /* Gets the sqrd radius */
    r2 *= r2;

    return glm::length2(owner.getPosition() - other.getPosition()) < r2;
}

Component* Collision::clone()
{
    return new Collision(*this);
}

void Collision::draw(GameObject& owner) /*Circle to show collisions*/
{
    //DrawCircleLines(owner.getPosition().x, owner.getPosition().y, m_radius, RED);
}
