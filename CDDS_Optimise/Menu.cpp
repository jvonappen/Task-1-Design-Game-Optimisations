#include "Menu.h"
#include "Game.h"
#include "raylib.h"
#include "PlayMode.h"
#include "TestMode.h"

void Menu::update(float delta)
{
	if (IsKeyPressed(KEY_ONE))
	{
		Game::instance().pushMode(new TestMode());
	}

	if (IsKeyPressed(KEY_TWO))
	{
		Game::instance().pushMode(new PlayMode());
	}
}

void Menu::draw()
{
	ClearBackground(BLACK);

	const char* text = "Press [1] for Optimisations Exercise \nPress [2] to play a game";
		int fontSize = 25;
		int fontWidth = MeasureText(text, fontSize);

		DrawText(text, GetScreenWidth() / 2 - fontWidth / 2, GetScreenHeight() / 2 - fontSize / 2, fontSize, RED);
}
