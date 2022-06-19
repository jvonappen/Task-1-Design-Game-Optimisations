#pragma once

#include "ResourceManager.h"

class Game
{
public:
	void load();
	void unload();
	void update(float delta);
	void draw();

	ResourceManager& resources() { return m_resources; }

private:
	ResourceManager m_resources;
};

