#pragma once
#include "GameObject.h"
#include "PlayMode.h"

class PlayMode;

class Player : public Component
{
public:
	Player(PlayMode& mode);

	void update(GameObject& owner, float delta) override;

	const char* getName() override { return "Player"; }
	Component* clone() override 
	{
		return new Player(*this);
	}

private:
	PlayMode& m_mode;
};

