#pragma once

#include "GameMode.h"

class Menu : public GameMode
{
public:
	void update(float delta) override;
	void draw() override;
};

