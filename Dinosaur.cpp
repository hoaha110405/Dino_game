#include "Dinosaur.h"

Dinosaur::Dinosaur()
{
	posX = 45;
	posY = GROUND;
	status = 0;
}

bool Dinosaur::On_Ground()
{
	return posY==GROUND;
}

void Dinosaur::Handle_Event(SDL_Event &e)
{
	if (e.type == SDL_KEYDOWN /*&& e.key.repeat == 0*/)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_UP:
		{
			if (On_Ground())
			{
				//Mix_PlayChannel(MIX_CHANNEL, gJump, NOT_REPEATITIVE);
				status = JUMP;
			}
			break;
		}
		case SDLK_SPACE:
		{
			if (On_Ground())
			{
				//Mix_PlayChannel(MIX_CHANNEL, gJump, NOT_REPEATITIVE);
				status = JUMP;
			}
			break;
		}
		case SDLK_DOWN:
		{
			if (On_Ground())
			{
				//Mix_PlayChannel(MIX_CHANNEL, gJump, NOT_REPEATITIVE);
				status = BOW;
			}
			break;
		}
		}
	}
	if (e.type == SDL_KEYUP)
	{
		switch (e.key.keysym.sym)
		{
		case SDLK_DOWN:
		{
			if (On_Ground())
			{
				status = RUN;
			}
		}
		}
	}
}

void Dinosaur::Move()
{
	if (status == JUMP)
	{
		posY -= JUMP_SPEED * NUMBER_OF_STEP;
		NUMBER_OF_STEP=NUMBER_OF_STEP-0.5;
		if (posY == GROUND) {
			NUMBER_OF_STEP = 10;
			status = RUN;
		}
	}
}

void Dinosaur::Dinosaur_Status(SDL_Renderer* gRenderer, SDL_Rect* currentClip_RUN, SDL_Rect* currentClip_JUMP, SDL_Rect* currentClip_BOW, BaseObject &gCharacterTexture, BaseObject& gCharacterTexture1)
{
	Move();
	if (status == JUMP) {
		gCharacterTexture.Render(posX, posY, gRenderer, currentClip_JUMP);
	}
	else if (status == RUN) {
		gCharacterTexture.Render(posX, posY, gRenderer, currentClip_RUN);
	}
	else if (status == BOW) {
		gCharacterTexture1.Render(posX, posY, gRenderer, currentClip_BOW);
	}
}

int Dinosaur::GetStatus()
{
	return status;
}

int Dinosaur::GetPosX()
{
	return posX;
}

int Dinosaur::GetPosY()
{
	return posY;
}