#pragma once
class CSprite
{
public:
	CSprite(SDL_Renderer* renderer, std::string filePath, int x, int y, int width, int height);
	~CSprite(void);

	void Draw(void);

	int GetX(void);
	int GetY(void);

	void SetX(int x);
	void SetY(int y);
	void SetPosition(int x, int y);

private:
	SDL_Texture* _image;
	SDL_Rect _rect;

	SDL_Renderer* _renderer;
};

