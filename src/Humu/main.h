#pragma once


int FPS = 60;
int frameDelay = 1000 / FPS;

unsigned long long int frameStart;
int frameTime;

Window* game = nullptr;

int main(int argc, char** argv) 
{
	Log::init();

	frameStart = SDL_GetTicks();
	game = new Window();
	int width = 1280;
	int height = 720;

	game->Init("Humu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, false);
	
	//opening
	int i = 0;
	while(i<6000 && game->isrunning) 
	{
		game->handleevents(true);
		game->opening(true, false, 2500);
		if (game->skip) 
		{
			game->opening(true, false, 1);
			break;
		}
		i++;
	
	}
	game->skip = false;
	i = 0;
	while (i < 6000 && game->isrunning && !(game->skip)) 
	{
		game->handleevents(true);
		game->opening(false, false, 0);
		i++;
	}
	

	//game
	while (game->isrunning)
	{
		game->update();
		game->handleevents(false);
		game->render();
		
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime) 
		{
			SDL_Delay(frameDelay = frameTime);
		}
	}



	
	return 0;
}

