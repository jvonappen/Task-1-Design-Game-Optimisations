#pragma once
#include "GameObject.h"

class PlayMode;

class Movement : public Component
{
public:
	Movement(PlayMode& mode);

	void update(GameObject& owner, float delta) override;

	const char* getName() override { return "Movement"; }
	
	Component* clone() override
	{
		return new Movement(*this);
	}


private:
	PlayMode& m_mode;

};

