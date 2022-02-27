// ALL IN SNAKE FORM 

#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "input.h"
using namespace std;

bool Input::AwaitSpacePress(float frameDelay)
{
	// Wait some time! Idk, he's done this before in snake!

	// Reuse GetAsyncKeyState, and look for a spacebar press

	// Wait 100ms

	// Look in snake left/right arrow

	return true;
}

void Input::WaitForRetry()
{	// Wait for space
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
}

