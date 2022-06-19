#pragma once

#include "ResourceManager.h"

class Game
{
public:
	void Load();
	void Unload();
	void Update(float delta);
	void Draw();

	ResourceManager& resources() { return m_resources; }

private:
	ResourceManager m_resources;
};

