#pragma once
#include "GameObject.h"

class Movement : public Component
{
public:
	Movement(float speed);
	void update(GameObject& owner, float delta) override;
	Component* clone() override { return new Movement(*this); }

private:
	float m_speed;
};

