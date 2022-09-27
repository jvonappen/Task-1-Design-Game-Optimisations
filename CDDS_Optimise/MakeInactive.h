#pragma once
#include "GameObject.h"

class MakeInactive : public Component
{
public:
	MakeInactive(float delay);
	void update(GameObject& owner, float delta) override;
	Component* clone() override;

	void resetTime() {m_time = 0;}

private:
	float m_delay;
	float m_time{ 0 };

};

