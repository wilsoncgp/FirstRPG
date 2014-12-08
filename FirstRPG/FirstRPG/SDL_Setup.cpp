#include "stdafx.h"
#include "SDL_Setup.h"


CSDL_Setup::CSDL_Setup(bool* quit, int screenWidth, int screenHeight)
{
	_window = NULL;
	_window = SDL_CreateWindow("My first RPG!", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN);

	if(_window == NULL)
	{
		std::cout << "Window couldn't be created" << std::endl;
		*quit = true;
		//return 0;
	}

	_renderer = NULL;
	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	_mainEvent = new SDL_Event();
}


CSDL_Setup::~CSDL_Setup(void)
{
	SDL_DestroyWindow(_window);
	SDL_DestroyRenderer(_renderer);
	delete _mainEvent;
}

SDL_Window* CSDL_Setup::GetWindow()
{
	return _window;
}

SDL_Renderer* CSDL_Setup::GetRenderer(void)
{
	return _renderer;
}

SDL_Event* CSDL_Setup::GetMainEvent(void)
{
	return _mainEvent;
}

void CSDL_Setup::Begin(void)
{
	SDL_PollEvent(_mainEvent);
	SDL_RenderClear(_renderer);

}

void CSDL_Setup::End(void)
{
	SDL_RenderPresent(_renderer);
}