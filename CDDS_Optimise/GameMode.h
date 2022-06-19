#pragma once
class GameMode
{
public:
	virtual void enter() {};
	virtual void exit() {};

	virtual void update(float delta) {};
	virtual void draw() {};
};

