// ALL IN SNAKE FORM 

#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "input.h"
using namespace std;

bool Input::SpacePressed()
{
	// should be fElapsedTime in here... lol

	/*
	if (bird.bHasCollided)
	{
		// Do nothing until user releases space
		if (m_keys[VK_SPACE].bReleased) { 
			bResetGame = true;
		}
	}
	*/

}

void Input::WaitForRetry()
{	// Wait for space
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
}

