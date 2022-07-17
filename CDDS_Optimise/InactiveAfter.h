#pragma once
#include "GameObject.h"
class InactiveAfter :public Component
{
public:
	InactiveAfter(float delay);

	void update(GameObject& owner, float delta) override;
	//const char* getName() override { return "Inactive"; }
	Component* clone() override;
	void reset() { m_time = 0; }

private:
	float m_delay;
	float m_time {0};
};

