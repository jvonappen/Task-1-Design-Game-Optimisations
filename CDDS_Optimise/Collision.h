#pragma once
#include "GameObject.h"


class Collision : public Component
{
public:
	Collision(float radius);
	const char* getName() override { return "Collision"; }
	bool checkCollision(GameObject& owner, GameObject& other, Collision& collider);


private:
	float m_radius {20};

};

