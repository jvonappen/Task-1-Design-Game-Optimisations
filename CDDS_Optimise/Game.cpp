#include "Game.h"

void Game::load()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
}

void Game::unload()
{
}

void Game::update(float delta)
{
}

void Game::draw()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
	DrawTexture(redDestroyer, 100, 100, RAYWHITE);
}
