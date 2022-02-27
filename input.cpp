// ALL IN SNAKE FORM 

#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "input.h"
using namespace std;

void Input::FlapWings(Bird bird)
{
	// should be fElapsedTime in here... lol

	if (bird.bHasCollided)
	{
		// Do nothing until user releases space
		if (m_keys[VK_SPACE].bReleased) { 
			bResetGame = true;
		}
	}
	else
	{

		if (m_keys[VK_SPACE].bPressed && bird.fBirdVelocity >= bird.minFallingVelocity) {
			bird.Flap();
		}
		else {
			bird.Fall(fElapsedTime);
		}

		if (fBirdAcceleration >= fGravity)
			fBirdAcceleration = fGravity;

		fBirdVelocity += fBirdAcceleration * fElapsedTime;
		fBirdPosition += fBirdVelocity * fElapsedTime;
		fLevelPosition += 14.0f * fElapsedTime;

		if (fLevelPosition > fSectionWidth)
		{
			fLevelPosition -= fSectionWidth;
			listSection.pop_front();
			int i = rand() % (ScreenHeight() - 20);
			if (i <= 10) i = 0;
			listSection.push_back(i);
		}


}

void Input::WaitForRetry()
{	// Wait for space
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
}

void Input::Reset()
{
	gameTickRate = startingGameTickRate;
}
