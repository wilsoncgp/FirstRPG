#pragma once
#include "SDL_Setup.h"
#include "Sprite.h"

class CMain
{
public:
	CMain(int screenWidth, int screenHeight);
	~CMain(void);

	void GameLoop(void);

private:
	int _screenWidth;
	int _screenHeight;
	bool _quit;

	CSDL_Setup* _sdlSetup;

	CSprite* _grass;
	CSprite* _bob;

	bool _moveUp;
	bool _moveLeft;
	bool _moveDown;
	bool _moveRight;

	unsigned int _timeCheck;
};

