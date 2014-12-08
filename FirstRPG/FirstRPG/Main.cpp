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

	_moveUp = false;
	_moveLeft = false;
	_moveDown = false;
	_moveRight = false;

	_timeCheck = SDL_GetTicks();
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

		_grass->Draw();
		_bob->Draw();

		switch (_sdlSetup->GetMainEvent()->type)
		{
		case SDL_KEYDOWN:
			switch (_sdlSetup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_w:
				//std::cout << "W key was pressed!" << std::endl;
				_moveUp = true;
				break;
			case SDLK_a:
				//std::cout << "A key was pressed!" << std::endl;
				_moveLeft = true;
				break;
			case SDLK_s:
				//std::cout << "S key was pressed!" << std::endl;
				_moveDown = true;
				break;
			case SDLK_d:
				//std::cout << "D key was pressed!" << std::endl;
				_moveRight = true;
				break;
			default:
				break;
			}
			break;
		case SDL_KEYUP:
			switch (_sdlSetup->GetMainEvent()->key.keysym.sym)
			{
			case SDLK_w:
				//std::cout << "W key was pressed!" << std::endl;
				_moveUp = false;
				break;
			case SDLK_a:
				//std::cout << "A key was pressed!" << std::endl;
				_moveLeft = false;
				break;
			case SDLK_s:
				//std::cout << "S key was pressed!" << std::endl;
				_moveDown = false;
				break;
			case SDLK_d:
				//std::cout << "D key was pressed!" << std::endl;
				_moveRight = false;
				break;
			default:
				break;
			}
			break;
			break;
		default:
			break;
		}

		if(_timeCheck + 10 < SDL_GetTicks())
		{
			if (_moveUp)
			{
				_bob->SetY(_bob->GetY() - 2);
			}
			if (_moveLeft)
			{
				_bob->SetX(_bob->GetX() - 2);
			}
			if (_moveDown)
			{
				_bob->SetY(_bob->GetY() + 2);
			}
			if (_moveRight)
			{
				_bob->SetX(_bob->GetX() + 2);
			}

			_timeCheck = SDL_GetTicks();
		}

		_sdlSetup->End();
	}
}