#pragma once
#include <iostream>
#include <thread>
#include <Windows.h>
#include <list>
#include "input.h"

using namespace std;

bool Input::AwaitSpacePress(int fps)
{
    bool spacePressed = false;
    // Poll for space every 1ms
    for (int i = 0; i < int((1000.0 / speedFactor) / fps); i++) {
        spaceHeld = (0x8000 & GetAsyncKeyState((unsigned char)('\x20')));
        spacePressed |= spaceHeld && !spaceHeldLastFrame;
        Sleep(1);
    }

    // Return true if waited long enough
    sinceLastSpace += 1000.0 / fps;
    bool validPress = spacePressed && sinceLastSpace > maxSpaceFrequency;
    if (validPress) {
        sinceLastSpace = 0;
    }
    spaceHeldLastFrame = spaceHeld;
    return validPress;
}

void Input::WaitForRetry()
{	// Wait for space
    bool spacePressed = false;

    while (!spacePressed)
    {
        spaceHeld = (0x8000 & GetAsyncKeyState((unsigned char)('\x20')));
        spacePressed = spaceHeld && !spaceHeldLastFrame;
        spaceHeldLastFrame = spaceHeld;
    }
}