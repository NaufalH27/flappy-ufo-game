#include "Player.h"
#include "SDL.h"
#include "log.h"


void Player::Gravity() 
{
	if (jumpState())
	{
		accelerator1 = accelerator1 + 0.0035;
		accelerator2 = accelerator2 + 0.0035;
		jumpHeight = jumpHeight + gravity;
		ypos = ypos + gravity + accelerator1 + accelerator2 + jumpHeight;
		destRec.y = ypos;

		
		if (jumpHeight > 0)
		{
			injump = false;
			jumpHeight = -6;
			accelerator1 = 0;
			accelerator2 = 0;
			gravity = 0.001;
		}
	}
	else
	{

		accelerator1 = accelerator1 + 0.00035;
		accelerator2 = accelerator2 + 0.00035;
		ypos = ypos + gravity + accelerator1 + accelerator2;
		destRec.y = ypos;
	}

}

void Player::jump()
{
	if (jumpTimer - lastJump > 60)
	{
		gravity = 0.2;
		accelerator1 = 0;
		accelerator2 = 0;
		injump = true;
		lastJump = jumpTimer;
	}
	else
	{
		Gravity();
	}
}

void Player::GetJumpTime()
{
	jumpTimer = SDL_GetTicks();

}

bool Player::jumpState() { return injump;}

void Player::applygravity()
{
	velocity = 0;
	velocity += 0.1;
	ypos += velocity;
}

void Player::set_hitboxPlayer()
{
	hitbox.x = xpos;
	hitbox.y = ypos;
	hitbox.w = 60.5;
	hitbox.h = 69;
}

bool Player::outsideFrame()
{
	if (ypos < -50 || ypos > 820)
	{
		return true;
	}
	else
	{
		return false;
	}
}

