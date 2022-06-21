#include "Game.h"
#include "Menu.h"

void Game::load()
{
	Texture2D redDestroyer = m_resources.loadTexture("res/11.png");

	Texture2D critters = m_resources.loadTexture("res/9.png");
	Texture2D destroyer = m_resources.loadTexture("res/10.png");

	pushMode(new Menu());
}

void Game::unload()
{
}

void Game::update(float delta)
{
	peekMode()->update(delta);
}

void Game::draw()
{
	//Texture2D redDestroyer = m_resources.loadTexture("res/11.png");
	//DrawTexture(redDestroyer, 100, 100, RAYWHITE);

	peekMode()->draw();
}

Game& Game::instance()
{
	static Game* instance = new Game();
	return *instance;
}

void Game::pushMode(GameMode* mode)
{
	if (m_gmode.size() > 0)
	{
		peekMode()->exit();
	}
	m_gmode.emplace(GameModePtr(mode));
	peekMode()->enter();
}

void Game::popMode(int count)
{
	for (int i = 0; i < count; i++)
	{
		m_gmode.pop();
	}
}

GameMode* Game::peekMode()
{
	return m_gmode.top().get();
}
