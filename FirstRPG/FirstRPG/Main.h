#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"
#include <math.h>

class CMain
{
public:
	CMain(int screenWidth, int screenHeight);
	~CMain(void);

	void GameLoop(void);
	double GetDistance(int x1, int y1, int x2, int y2);

private:
	int _screenWidth;
	int _screenHeight;
	bool _quit;

	CSDL_Setup* _sdlSetup;

	CSprite* _grass;
	CSprite* _bob;

	unsigned int _timeCheck;
	int _mouseX;
	int _mouseY;
};

