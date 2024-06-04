#include "object.h"


Object::Object()
{

}

Object::~Object()
{

}

SDL_Renderer* Object::objectRenderer = nullptr;

void Object::createTexture(const char* filePath, double h, double w)
{
	height = h;
	width = w;

	objectTempSurface = IMG_Load(filePath);
	Texture = SDL_CreateTextureFromSurface(objectRenderer, objectTempSurface);
	SDL_FreeSurface(objectTempSurface);
}


double Object::centerX(double windowWidht)
{
    return (windowWidht - width) / 2;
}

double Object::centerY(double windowHeight)
{
    return (windowHeight - height) / 2;
}
void Object::update()
{
	
}
void Object::set_coordinates(double x, double y)
{
    xpos = x;
    ypos = y;
    originalX = x;
    originalY = y;
}

void Object::set_destR()
{
    destRec.h = height;
    destRec.w = width;
    destRec.x = xpos;
    destRec.y = ypos;

}

void Object::set_toOriginalCoordiante()
{
    xpos = originalX;
    ypos = originalY;
}

void Object::set_Hitbox()
{
    hitbox.x = xpos;
    hitbox.y = ypos;
    hitbox.w = width - (width * 0.075);
    hitbox.h = height - (height * 0.075);
}

void Object::render(SDL_Rect* srcR, SDL_Rect* destR)
{
	SDL_RenderCopy(objectRenderer, Texture, srcR, destR);
}

void Object::moveToLeft()
{
    xpos -= 0.5;
}



void Object::fadeTexture(bool Fading, Uint32 duration)
{
    Uint8 alpha;
    SDL_GetTextureAlphaMod(Texture, &alpha);

    Uint32 step = 255 * SDL_GetTicks()/duration;

    if (Fading == false) {
        alpha = (step < 255) ? step : 255;
    }
    else {
        alpha = (step > 0) ? (255 - step) : 0;
    }

    SDL_SetTextureAlphaMod(Texture, alpha);

}

void Object::set_score()
{
    score.x = xpos;
    score.y = ypos;
    score.w = 1;
    score.h - 1280;
}

