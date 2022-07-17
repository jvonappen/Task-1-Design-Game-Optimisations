#pragma once
#include "GameObject.h"


class Collision : public Component
{
public:
	Collision(float radius);

	bool checkCollision(GameObject& owner, GameObject& other, Collision& collider);

	Component* clone() override;


private:
	float m_radius {20};

};

