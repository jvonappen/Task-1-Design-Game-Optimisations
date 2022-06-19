#include "Game.h"

void Game::Load()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
}

void Game::Unload()
{
}

void Game::Update(float delta)
{
}

void Game::Draw()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
	DrawTexture(redDestroyer, 100, 100, RAYWHITE);
}
