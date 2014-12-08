#include "stdafx.h"
#include "Sprite.h"


CSprite::CSprite(SDL_Renderer* renderer, std::string filePath, int x, int y, int width, int height)
{
	_renderer = renderer;
	_image = NULL;
	_image = IMG_LoadTexture(_renderer, filePath.c_str());

	if(_image == NULL)
	{
		std::cout << "Couldn't Load " << filePath.c_str() << std::endl;
	}

	_rect.x = x;
	_rect.y = y;
	_rect.w = width;
	_rect.h = height;
}


CSprite::~CSprite(void)
{
	SDL_DestroyTexture(_image);
}

void CSprite::Draw(void)
{
	SDL_RenderCopy(_renderer, _image, NULL, &_rect);
}

int CSprite::GetX(void)
{
	return _rect.x;
}

int CSprite::GetY(void)
{
	return _rect.y;
}

void CSprite::SetX(int x)
{
	_rect.x = x;
}

void CSprite::SetY(int y)
{
	_rect.y = y;
}

void CSprite::SetPosition(int x, int y)
{
	_rect.x = x;
	_rect.y = y;
}
