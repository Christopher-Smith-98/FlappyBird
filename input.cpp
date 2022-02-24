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
	if (bHasCollided)
	{
		// Do nothing until user releases space
		if (m_keys[VK_SPACE].bReleased)
			bResetGame = true;
	}
	else
	{

		if (m_keys[VK_SPACE].bPressed && fBirdVelocity >= fGravity / 10.0f)
		{
			fBirdAcceleration = 0.0f;
			fBirdVelocity = -fGravity / 4.0f;
			nFlapCount++;
			if (nFlapCount > nMaxFlapCount)
				nMaxFlapCount = nFlapCount;
		}
		else
			fBirdAcceleration += fGravity * fElapsedTime;

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
