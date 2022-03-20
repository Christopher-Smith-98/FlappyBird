#pragma once

// forward declarations
class Bird;

using namespace std;

class Input
{
public:
	bool bKeySpace = false, bKeySpaceOld = false;
	float gameTickRate = 200.0;
	float startingGameTickRate = gameTickRate;
	float aspectratio = 0.6;

    float sinceLastSpace = 0;
    float maxSpaceFrequency = 250;
    bool spaceHeldLastFrame = false;
	int fps = 60;
	bool spacePressed = false;
    bool spaceHeld = false;
    float speedFactor = 10;

	void WaitForRetry();
	void Reset();
	bool AwaitSpacePress(int fps);
};
