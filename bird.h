#pragma once

#include <list>
class Graphics;
class Input;
using namespace std;

// where bird drawing is going, probably.

class Bird
{
public:
	int nScore;
	int direction;
	bool bDead;
	list<sBirdBody> body;

	void Reset();
	void Move();
	void CheckCollision(Graphics graphics, Input& input);
};