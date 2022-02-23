// Includes
#include <iostream>
#include <thread>
#include <list>
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
			// Update Snake Direction
			input.UpdateDirection(bird.direction);
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

