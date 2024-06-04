#pragma once
#include "object.h"
#include "SDL.h"
#include "SDL_image.h"
#include <vector>
#include "Log.h"


Object* tower1 = new Object;
Object* tower2 = new Object;
Object* tower3 = new Object;
Object* tower4 = new Object;
Object* tower5 = new Object;
Object* tower6 = new Object;
Object* tower7 = new Object;
Object* tower8 = new Object;
Object* tower9 = new Object;
Object* tower10 = new Object;
Object* tower11 = new Object;
Object* tower12 = new Object;



void createTower()
{
	tower1->createTexture("Assets/building1.png", 492, 138);
	tower2->createTexture("Assets/building1.png", 492, 138);
	tower3->createTexture("Assets/building1.png", 492, 138);
	tower4->createTexture("Assets/building2.png", 492, 138);
	tower5->createTexture("Assets/building2.png", 492, 138);
	tower6->createTexture("Assets/building2.png", 492, 138);
	tower7->createTexture("Assets/building1.png", 492, 138);
	tower8->createTexture("Assets/building1.png", 492, 138);
	tower9->createTexture("Assets/building1.png", 492, 138);
	tower10->createTexture("Assets/building2.png", 492, 138);
	tower11->createTexture("Assets/building2.png", 492, 138);
	tower12->createTexture("Assets/building2.png", 492, 138);
	
}

void set_towerCoordinates(int xpos) 
{
	
	tower1->set_coordinates(xpos, 400);
	tower2->set_coordinates(xpos + (1 * 700), 350);
	tower3->set_coordinates(xpos + (2 * 700), 500);
	tower4->set_coordinates(xpos + 5, -300);
	tower5->set_coordinates(xpos + (1 * 700) + 5, -350);
	tower6->set_coordinates(xpos + (2 * 700) + 5, -300);

	tower7->set_coordinates(xpos + (3 * 700), 400);
	tower8->set_coordinates(xpos + (4 * 700), 350);
	tower9->set_coordinates(xpos + (5 * 700), 500);
	tower10->set_coordinates(xpos + (3 * 700) + 5, -300);
	tower11->set_coordinates(xpos + (4 * 700) + 5, -350);
	tower12->set_coordinates(xpos + (5 * 700) + 5, -300);
	

	
}

void set_towerDestR()
{
	tower1->set_destR();
	tower2->set_destR();
	tower3->set_destR();
	tower4->set_destR();
	tower5->set_destR();
	tower6->set_destR();
	tower7->set_destR();
	tower8->set_destR();
	tower9->set_destR();
	tower10->set_destR();
	tower11->set_destR();
	tower12->set_destR();

}

void moveTowerToLeft()
{
	tower1->moveToLeft();
	tower2->moveToLeft();
	tower3->moveToLeft();
	tower4->moveToLeft();
	tower5->moveToLeft();
	tower6->moveToLeft();
	tower7->moveToLeft();
	tower8->moveToLeft();
	tower9->moveToLeft();
	tower10->moveToLeft();
	tower11->moveToLeft();
	tower12->moveToLeft();
}

void renderTower()
{
	tower1->render(NULL, &(tower1->destRec));
	tower2->render(NULL, &(tower2->destRec));
	tower3->render(NULL, &(tower3->destRec));
	tower4->render(NULL, &(tower4->destRec));
	tower5->render(NULL, &(tower5->destRec));
	tower6->render(NULL, &(tower6->destRec));
	tower7->render(NULL, &(tower7->destRec));
	tower8->render(NULL, &(tower8->destRec));
	tower9->render(NULL, &(tower9->destRec));
	tower10->render(NULL, &(tower10->destRec));
	tower11->render(NULL, &(tower11->destRec));
	tower12->render(NULL, &(tower12->destRec));
}

void set_towerHitbox()
{
	tower1->set_Hitbox();
	tower2->set_Hitbox();
	tower3->set_Hitbox();
	tower4->set_Hitbox();
	tower5->set_Hitbox();
	tower6->set_Hitbox();

}

void set_towerOriginalCoordiantes()
{
	tower1->set_toOriginalCoordiante();
	tower2->set_toOriginalCoordiante();
	tower3->set_toOriginalCoordiante();
	tower4->set_toOriginalCoordiante();
	tower5->set_toOriginalCoordiante();
	tower6->set_toOriginalCoordiante();
	tower7->set_toOriginalCoordiante();
	tower8->set_toOriginalCoordiante();
	tower9->set_toOriginalCoordiante();
	tower10->set_toOriginalCoordiante();
	tower11->set_toOriginalCoordiante();
	tower12->set_toOriginalCoordiante();
}

void set_towerScoreArea()
{
	tower1->set_score();
	tower2->set_score();
	tower3->set_score();

}

bool reachend()
{
	if (tower3->xpos == -100)
	{
		set_towerCoordinates(600);
		return true;

	}
	else
	{
		return false;
	}
}

bool addScore()
{
	if (tower1->xpos == 17 || tower2->xpos == 17 || tower3->xpos == 17)
	{
		return true;
	}
	else
	{

	}
	{
		return false;
	}
}



