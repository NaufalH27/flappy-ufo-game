#include "window.h"
#include "log.h"
#include "object.h"
#include "function.h"
#include "Player.h"
#include "tower.h"




Object* Background = new Object;
Object* startButton = new Object;
Object* Credit = new Object;
Object* startClick = new Object;
Object* exitButton = new Object;
Object* exitClick = new Object;
Player* player = new Player;



 bool startClicked;
 bool started;
 bool startClickedBeforeRelease;
 bool exitClicked;
 bool exitClickedBeforeRelease;
 bool collided;
 bool startAfterCollided;
 bool firstClick;
 bool gameplayExit = false;
 bool isreachend = false;
 bool isJumping = false;

 int score = 0;

Window::Window() 
{

}

Window::~Window() 
{

}

void Window::Init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) 
{

	int flags = 0;
	if (fullscreen) {
		flags = SDL_WINDOW_FULLSCREEN;
		}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		HM_CLIENT_INFO("Initialized");
			
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
	
		if (window)
		{
			windowWidth = width;
			windowHeight = height;
			HM_CLIENT_INFO("Window Terbuat");
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			Object::objectRenderer = renderer;
			HM_CLIENT_INFO("Render berhasil");
		}

		isrunning = true;

	}

	Background->createTexture("Assets/Background.png",0,0);
	startButton->createTexture("Assets/Start.png", 131, 315);
	startClick->createTexture("Assets/Start2.png", 134, 321);
	exitButton->createTexture("Assets/Exit.png", 131, 315);
	exitClick->createTexture("Assets/Exit2.png", 134, 321);
	Credit->createTexture("Assets/Credit.png",365, 684);
	player->createTexture("Assets/player.png", 105, 120);
	createTower();

	startButton->set_coordinates(startButton->centerX(windowWidth), startButton->centerY(windowHeight) - 100);
	startClick->set_coordinates(startClick->centerX(windowWidth), startClick->centerY(windowHeight) - 100);
	exitButton->set_coordinates(exitButton->centerX(windowWidth), exitButton->centerY(windowHeight) + 75);
	exitClick->set_coordinates(exitClick->centerX(windowWidth), exitClick->centerY(windowHeight) + 75);
	Credit->set_coordinates(Credit->centerX(windowWidth), Credit->centerY(windowHeight));
	player->set_coordinates(20, player->centerY(windowHeight));
	set_towerCoordinates(1300);

	}


void Window::handleevents(bool isOpening) 
{

	player->GetJumpTime();
	SDL_Event event;
	SDL_PollEvent(&event);

	if (isOpening) 
	{
		if (event.type == SDL_QUIT) 
		{
			isrunning = false;
			return;
		}

		else if (event.type == SDL_MOUSEBUTTONUP) 
		{
			skip = true;
			return;
		}
    }

	switch(event.type)
	{

	case SDL_QUIT:
		isrunning = false;
		break;

	case SDL_MOUSEBUTTONDOWN:

		if (IsMouseInArea(event.button.x, event.button.y, startButton->destRec) && !started) 
		{
			startClicked = true;
			startClickedBeforeRelease = true;
			HM_CLIENT_INFO("start button Clicked");
		}

		else if (IsMouseInArea(event.button.x, event.button.y, exitButton->destRec) && !started)
		{
			exitClickedBeforeRelease = true;
			exitClicked = true;
			HM_CLIENT_INFO("Exit button Clicked");
		}

		if (started) 
		{
			isJumping = true;
		}

		if (collided)
		{
			startAfterCollided = true;
		}

		break;

	case SDL_MOUSEBUTTONUP:

		if (IsMouseInArea(event.button.x, event.button.y, startClick->destRec) && startClickedBeforeRelease && !started)
		{
			startClicked = false;
			firstClick = true;
			HM_CLIENT_INFO("Game Started");	
		}

		else if (IsMouseInArea(event.button.x, event.button.y, exitClick->destRec) && exitClickedBeforeRelease && !started)
		{
			exitClicked = true;
			HM_CLIENT_INFO("game terminated");
			isrunning = false;
		}

		startClickedBeforeRelease = false;
		exitClickedBeforeRelease = false;
		exitClicked = false;
		startClicked = false;

	case SDL_KEYDOWN: 

		if (event.key.keysym.sym == SDLK_ESCAPE) 
		{
			gameplayExit = true;
		}

	default:
		break;
		
	}
}

void Window::opening(bool Fading, bool CreditFading,int duration)
{
	Credit->set_destR();

	if (Fading)
	{
		Credit->fadeTexture(CreditFading, duration);
	}

	SDL_RenderClear(renderer);
	Background->render(NULL, NULL);
	Credit->render(NULL, &(Credit->destRec));
	SDL_RenderPresent(renderer);
}

void Window::update()
{

	startButton->set_destR();
	startClick->set_destR();
	exitButton->set_destR();
	exitClick->set_destR();
	player->set_destR();
	player->set_hitboxPlayer();
	set_towerDestR();
	set_towerHitbox();
	set_towerScoreArea();

	if (started) 
	{
		isreachend = reachend();

		if (is_collision(player->hitbox, tower1->hitbox) || is_collision(player->hitbox, tower2->hitbox) ||
			is_collision(player->hitbox, tower3->hitbox) || is_collision(player->hitbox, tower4->hitbox) ||
			is_collision(player->hitbox, tower5->hitbox) || is_collision(player->hitbox, tower6->hitbox) ||
			player->outsideFrame())
		{
			collided = true;
		}

		if (addScore())
		{
			score++;
			HM_CLIENT_INFO(score);
		}

		moveTowerToLeft();
		startButton -> ypos -= 1;
		exitButton -> ypos -= 1;

		if (isJumping) 
		{
			if (!player->jumpState())
			{
				player->jump();
			}

			isJumping = !player->jumpState();
				
		}

		else
		{
			player->Gravity();

		}
	}

	else if (firstClick)
	{
		if (!player->jumpState())
		{
			player->jump();
		}

		started = true;
		firstClick = false;

	}
}

void Window::render()
{
	SDL_RenderClear(renderer);
	Background->render(NULL, NULL);
	player->render(NULL, &(player->destRec));
	renderTower();

	if (!started) 
	{
		//Start Button
		if (!startClicked) 
		{
			startButton->render(NULL, &(startButton->destRec));
		}
		
		else 
		{
			startClick->render(NULL, &(startClick->destRec));
		}

		//Exit Button
		if (!exitClicked) 
		{
			exitButton->render(NULL, &(exitButton->destRec));
		}

		else 
		{
			exitClick->render(NULL, &(exitClick->destRec));
		}
	}

	else {
		startButton->render(NULL, &(startButton->destRec));
		exitButton->render(NULL, &(exitButton->destRec));
		player->render(NULL, &(player->destRec));
		renderTower();

		if (collided) 
		{
			started = false;
		}

	}

	if (gameplayExit)
	{
		HM_CLIENT_INFO("Player exit");
		set_towerCoordinates(1300);
		collided = false;
		player->set_toOriginalCoordiante();
		set_towerOriginalCoordiantes();
		startButton->set_toOriginalCoordiante();
		exitButton->set_toOriginalCoordiante();
		started = false;
		startAfterCollided = false;
		gameplayExit = false;
		score = 0;
	}

	if (startAfterCollided)
	{
		set_towerCoordinates(1300);
		firstClick = true;
		collided = false;
		player->set_toOriginalCoordiante();
		set_towerOriginalCoordiantes();
		started = true;
		startAfterCollided = false;
		score = 0;
	}

	SDL_RenderPresent(renderer);
}

void Window::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	HM_CLIENT_INFO("Game Cleaned");
}

