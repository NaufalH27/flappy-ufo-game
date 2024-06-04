#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Window {
public:
	Window();
	~Window();

	void Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		
	void handleevents(bool isopening);
	void opening(bool Fading, bool CreditFading,int duration);
	void update();


	void render();
	void clean();
	bool isrunning, skip;

	int windowWidth, windowHeight;

	

private:
	SDL_Window* window;
	SDL_Renderer* renderer;



	};
