#include "Menu.h"
#include "Game.h"
#include "raylib.h"

void Menu::update(float delta)
{
	if (IsKeyPressed(KEY_SPACE))
	{
		//Game::instance().pushMode();
	}
}

void Menu::draw()
{
	ClearBackground(BLACK);

	const char* text = "Press [SPACE] to start";
		int fontSize = 50;
		int fontWidth = MeasureText(text, fontSize);

		DrawText(text, GetScreenWidth() / 2 - fontWidth / 2, GetScreenHeight() / 2 - fontSize / 2, fontSize, RED);
}
