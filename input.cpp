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

	this_thread::sleep_for(scrollSpeed);
	return (((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0));
	
	
}

void Input::WaitForRetry()
{	// Wait for space
	while ((0x8000 & GetAsyncKeyState((unsigned char)('\x20'))) == 0);
}

void Input::FlapWings()
{
}