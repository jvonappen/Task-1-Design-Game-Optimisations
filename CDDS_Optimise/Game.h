#pragma once

#include "ResourceManager.h"
#include "GameMode.h"
#include <stack>
#include <memory>


class Game
{
public:
	void load();
	void unload();
	void update(float delta);
	void draw();

	ResourceManager& resources() { return m_resources; }

	void pushMode(GameMode* mode);
	void popMode(int count = 1);
	GameMode& peekMode();
	

private:
	ResourceManager m_resources;

	std::stack<std::unique_ptr<GameMode>> m_gmode;
};

