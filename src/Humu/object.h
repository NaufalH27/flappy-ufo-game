#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Object
{
public:
	Object();

	~Object();

	void createTexture(const char* filePath, double h, double w);
	void render(SDL_Rect* srcR, SDL_Rect* destR);
	void fadeTexture(bool Fading, Uint32 duration);
	void set_destR();
	void set_coordinates(double x, double y);
	double centerX(double windowWidth);
	double centerY(double windowHeight);
	void set_toOriginalCoordiante();
	void set_Hitbox();
	void set_score();

	void update();

	void moveToLeft();

	static SDL_Renderer* objectRenderer;

	double originalX, originalY;
	SDL_Texture* Texture;
	double width, height;
	SDL_Rect destRec, hitbox;
	double xpos, ypos;
	SDL_Surface* objectTempSurface;
	SDL_Rect score;


};