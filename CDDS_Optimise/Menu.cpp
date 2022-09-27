#include "Menu.h"
#include "Game.h"
#include "raylib.h"
#include "PlayMode.h"


void Menu::update(float delta)
{
	if (IsKeyPressed(KEY_ENTER))
	{
		Game::instance().pushMode(new PlayMode());
	}
}

void Menu::draw()
{
	ClearBackground(RAYWHITE);

	const char* text = "------------	Optimisations Exercise	------------\n This example includes the following:\n - A Double-Linked list in the form of an Object Pool\n - Hashing Techniques by implementing a Resource Manager\n This is demonstrated by spawing up to an additionall\n 1500 critters without decreasing the FPS below 60.\n \n Use W,A,S,D keys to move the red Octopus.\n Press [SPACE] to spawn additional red critters.\n The critters will disapear after 60s.\n  \n Please see the ExtraInfo.txt for more information\n \n	------------	Press [ENTER] to continue	------------";
		int fontSize = 20;
		int fontWidth = MeasureText(text, fontSize);

		DrawText(text, GetScreenWidth() / 2 - fontWidth / 2, 5, fontSize, BLACK);
}
