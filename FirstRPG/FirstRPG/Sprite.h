#pragma once
#include "Vector2D.h"

class CSprite
{
public:
	CSprite(SDL_Renderer* renderer, std::string filePath, int x, int y, int width, int height);
	~CSprite(void);

	void Draw(void);

	int GetX(void);
	int GetY(void);
	CVector2D GetPosition(void);

	void SetX(int x);
	void SetY(int y);
	void SetPosition(int x, int y);
	void SetPosition(CVector2D pos);

private:
	SDL_Texture* _image;
	SDL_Rect _rect;

	CVector2D _position;

	SDL_Renderer* _renderer;
};

