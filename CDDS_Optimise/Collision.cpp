#include "Collision.h"
#include <glm/gtx/norm.hpp>

Collision::Collision(float radius) : m_radius(radius)
{

}

bool Collision::checkCollision(GameObject& owner, GameObject& other, Collision& collider)
{
    float r2 = m_radius + collider.m_radius;        /* Gets the sqrd radius */
    r2 *= r2;

    return glm::length2(owner.getPosition() - other.getPosition()) < r2;
}
