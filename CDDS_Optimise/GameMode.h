#pragma once
#include <memory>

class GameMode
{
public:
	virtual void enter() {};
	virtual void exit() {};

	virtual void update(float delta) {};
	virtual void draw() {};
};

using GameModePtr = std::unique_ptr<GameMode>;