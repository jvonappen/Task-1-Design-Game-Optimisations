#include "Game.h"

void Game::load()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");

	Texture2D critters = m_resources.loadTexture("res/9.png");
	Texture2D destroyer = m_resources.loadTexture("res/10.png");
}

void Game::unload()
{
}

void Game::update(float delta)
{
	//peekMode().update(delta);
}

void Game::draw()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
	DrawTexture(redDestroyer, 100, 100, RAYWHITE);

	//peekMode().draw();
}

void Game::pushMode(std::unique_ptr<GameMode>& mode)
{
	m_gmode.push(std::move(mode));
}

void Game::popMode(int count)
{
	for (int i = 0; i < count; i++)
	{
		m_gmode.pop();
	}
}

GameMode& Game::peekMode()
{
	return *m_gmode.top();
}
