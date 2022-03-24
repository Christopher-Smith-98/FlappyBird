#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "graphics.h"
#include "bird.h"
#include "input.h"
using namespace std;

void Bird::Reset(int screenHeight)
{
	if (bResetGame)
	{
		bHasCollided = false;
		bResetGame = false;
		yAcceleration = 0.0f;
		yVelocity = 0.0f;
		xPosition = 20;
		yPosition = screenHeight / 2.0f;
		nFlapCount = 0;
		bResetGame = false;
		nAttemptCount++;
	}
}

void Bird::CheckCollision(Graphics graphics)
{
	bHasCollided = yPosition < 2 || yPosition > graphics.height - 2; // ||
	//			   graphics.screen[(int)(yPosition + 0) * graphics.width + xPosition    ] != ' ' ||
	//			   graphics.screen[(int)(yPosition + 1) * graphics.width + xPosition    ] != ' ' ||
	//			   graphics.screen[(int)(yPosition + 0) * graphics.width + xPosition + 6] != ' ' ||
	//			   graphics.screen[(int)(yPosition + 1) * graphics.width + xPosition + 6] != ' ';
}

void Bird::Flap() 
{
	if (yVelocity >= minFallingVelocity) 
	{
		yAcceleration = 0.0f;
		yVelocity = -fGravity / 4.0f;
		nFlapCount++;
		if (nFlapCount > nMaxFlapCount) {
			nMaxFlapCount = nFlapCount;
		}
	}
}

void Bird::Fall(float fElapsedTime)
{
	yAcceleration += fGravity * fElapsedTime;
	if (yAcceleration >= fGravity) {
		yAcceleration = fGravity;
	}
}

void Bird::Update(float fElapsedTime) 
{
	fElapsedTime /= 10000.0f;
	Fall(fElapsedTime);
	yVelocity += yAcceleration * fElapsedTime;
	yPosition += yVelocity * fElapsedTime;
}