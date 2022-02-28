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
float frameDelay = 100;   // milliseconds

int main()
{
	Input input;
	Graphics graphics;
	Bird bird;
	Pipes pipes;

	graphics.CreateBuffer(nScreenWidth, nScreenHeight);

	while (1)
	{
		bird.Reset();
		pipes.Reset();
		while (!bird.bHasCollided) //ElapsedTime should be here
		{
			// Update Bird DirectionFlap
			if (input.AwaitSpacePress(frameDelay)) {
				bird.Flap();
			}
			// Call update functions
			bird.Update(frameDelay);
			pipes.Update(frameDelay);
			bird.CheckCollision(graphics);

			// Draw screen
			graphics.Draw(bird);
		}
		input.WaitForRetry();
	}
	return 0;
}