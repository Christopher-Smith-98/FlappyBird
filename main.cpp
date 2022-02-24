// Includes
#include <iostream>
#include <thread>
#include <list>
#include <string>
#include <Windows.h>
#include "bird.h"
#include "pipe.h"
#include "input.h"
#include "graphics.h"

using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 30;

int main()
{
	Input input;
	Graphics graphics;
	Bird bird;

	graphics.CreateBuffer(nScreenWidth, nScreenHeight);

	while (1)
	{

		bird.Reset();
		while (!bird.bDead)
		{
			// Update Snake DirectionFlap
			input.FlapWings(bird);
			bird.Move();
			bird.CheckCollision(graphics, input);

			// Draw screen
			graphics.Draw(bird);
		}
		input.WaitForRetry();
		input.Reset();
	}
	return 0;
}




/*
class FlappyBird
{



protected:
	// Called by olcConsoleGameEngine
	virtual bool OnUserCreate()
	{
		listSection = { 0, 0, 0, 0 };
		bResetGame = true;
		fSectionWidth = (float)ScreenWidth() / (float)(listSection.size() - 1);
		return true;
	}

	// Called by olcConsoleGameEngine
	virtual bool OnUserUpdate(float fElapsedTime)
	{
		

		return true;
	}
};


int main()
{
	// Use olcConsoleGameEngine derived app
	FlappyBird game;
	game.ConstructConsole(80, 48, 16, 16);
	game.Start();

	return 0;
}
*/