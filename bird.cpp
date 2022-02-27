#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "graphics.h"
#include "bird.h"
#include "input.h"
using namespace std;

void Bird::Reset()
{
	if (bResetGame)
	{
		bHasCollided = false;
		bResetGame = false;
		fBirdAcceleration = 0.0f;
		fBirdVelocity = 0.0f;
		fBirdPosition = ScreenHeight() / 2.0f;
		nFlapCount = 0;
		bResetGame = false;
		nAttemptCount++;
	}
}

void Bird::Move()
{
	
}

void Bird::CheckCollision(Graphics graphics, Input& input)
{
	
}

void Bird::Flap() 
{
	fBirdAcceleration = 0.0f;
	fBirdVelocity = -fGravity / 4.0f;
	nFlapCount++;
	if (nFlapCount > nMaxFlapCount) {
		nMaxFlapCount = nFlapCount;
	}
}

void Bird::Fall(float fElapsedTime) 
{
	fBirdAcceleration += fGravity * fElapsedTime;
}
