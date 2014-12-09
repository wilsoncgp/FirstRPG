#include "stdafx.h"
#include "Main.h"


CMain::CMain(int screenWidth, int screenHeight)
{
	_screenWidth = screenWidth;
	_screenHeight = screenHeight;

	_quit = false;

	_sdlSetup = new CSDL_Setup(&_quit, screenWidth, screenHeight);

	_grass = new CSprite(_sdlSetup->GetRenderer(), "data/grass.bmp", 0, 0, screenWidth, screenHeight);
	_bob = new CSprite(_sdlSetup->GetRenderer(), "data/bob.png", 300, 250, 50, 100);

	_timeCheck = SDL_GetTicks();
	_mouseX = 0;
	_mouseY = 0;
}


CMain::~CMain(void)
{
	delete _grass;
	delete _bob;
}

void CMain::GameLoop(void)
{
	while(!_quit && _sdlSetup->GetMainEvent()->type != SDL_QUIT)
	{
		_sdlSetup->Begin();
		SDL_GetMouseState(&_mouseX, &_mouseY);

		_grass->Draw();
		_bob->Draw();

		if(_timeCheck + 10 < SDL_GetTicks())
		{
			float distance = GetDistance(_bob->GetX(), _bob->GetY(), _mouseX, _mouseY);

			if (_bob->GetX() > _mouseX)
			{
				_bob->SetX(_bob->GetX() - ((_bob->GetX() - _mouseX / distance) * 1.5f));
			}
			if (_bob->GetX() < _mouseX)
			{
				_bob->SetX(_bob->GetX() + ((_bob->GetX() - _mouseX / distance) * 1.5f));
			}
			if (_bob->GetY() > _mouseY)
			{
				_bob->SetY(_bob->GetY() - ((_bob->GetY() - _mouseY / distance) * 1.5f));
			}
			if (_bob->GetY() < _mouseY)
			{
				_bob->SetY(_bob->GetY() + ((_bob->GetY() - _mouseY / distance) * 1.5f));
			}

			_timeCheck = SDL_GetTicks();
		}

		_sdlSetup->End();
	}
}

double CMain::GetDistance(int x1, int y1, int x2, int y2)
{
	return sqrt(((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2)));
}