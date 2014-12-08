#pragma once
class CSDL_Setup
{
public:
	CSDL_Setup(bool* quit, int screenWidth, int screenHeight);
	~CSDL_Setup(void);

	SDL_Window* GetWindow(void);
	SDL_Renderer* GetRenderer(void);
	SDL_Event* GetMainEvent(void);

	void Begin(void);
	void End(void);

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SDL_Event* _mainEvent;
};

