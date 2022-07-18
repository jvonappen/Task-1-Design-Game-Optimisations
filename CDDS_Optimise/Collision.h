#pragma once
#include "GameObject.h"
/*01:00*/

class Collision : public Component
{
public:
	Collision(float radius);

	bool checkCollision(GameObject& owner, GameObject& other, Collision& collision);

	Component* clone() override;

	/*Circle*/
	void draw(GameObject& owner) override;

private:
	float m_radius {15};

};

