#pragma once
#include "GameObject.h"


class Collision : public Component
{
public:
	Collision(float radius);

	bool checkCollision(GameObject& owner, GameObject& other, Collision& collider);
	const char* getName() override { return "Collision"; }
	Component* clone() override;


private:
	float m_radius {20};

};

