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
	return _position.GetX();
}

int CSprite::GetY(void)
{
	return _position.GetY();
}

CVector2D CSprite::GetPosition(void)
{
	return _position;
}

void CSprite::SetX(int x)
{
	_position.SetX(x);
	_rect.x = x - (int) ((float)_rect.w / 2.0f);
}

void CSprite::SetY(int y)
{
	_position.SetY(y);
	_rect.y = y - _rect.h;
}

void CSprite::SetPosition(int x, int y)
{
	_position.SetPosition(x, y);
	_rect.x = x - (int) ((float)_rect.w / 2.0f);
	_rect.y = y - _rect.h;
}

void CSprite::SetPosition(CVector2D pos)
{
	_position = pos;
	_rect.x = pos.GetX() - (int) ((float)_rect.w / 2.0f);
	_rect.y = pos.GetY() - _rect.h;
}
