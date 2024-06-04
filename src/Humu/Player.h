#pragma once
#include "object.h"

class Player : public Object
{
public:
	void Gravity();
	void GetJumpTime();
	void jump();
	bool jumpState();
	void applygravity();
	void set_hitboxPlayer();
	bool outsideFrame();

	double gravity = 0.001;
	double jumpHeight = -6;
	double accelerator1 = 0;
	double accelerator2 = 0;
	bool injump = false;
	double velocity = 0;



	double jumpTimer;
	double lastJump = 0;


};

