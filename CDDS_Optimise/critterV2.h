#pragma once
#include "GameObject.h"

class CritterV2 : public Component
{
public:
	CritterV2(float speed);

	void update(GameObject& owner, float delta) override;
	const char* getName() override { return "CritterV2"; }
	Component* clone() override;

private:
	float m_speed;


};

