#pragma once

#include <list>
class Graphics;
class Input;
using namespace std;

// where bird drawing is going, probably.

class Bird
{
public:
	const float fGravity = 100.0f;
	const float minFallingVelocity = fGravity / 10.0f;

	int   xPosition;
	float yPosition;
	float yVelocity;
	float yAcceleration;
	bool bHasCollided = false;
	
	int nFlapCount;
	bool bResetGame;

	// Never changed after startup
	int nMaxFlapCount = 0;
	int nAttemptCount = 0;

	void Reset(int screenHeight);
	void CheckCollision(Graphics graphics);
	void Flap();
	void Fall(float fElapsedTime);
	void Update(float fElapsedTime);
};