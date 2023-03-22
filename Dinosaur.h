#ifndef DINOSAUR_H
#define DINOSAUR_H

#include "BaseObject.h"

#define JUMP 1
#define RUN	0
#define BOW 2


class Dinosaur {
public:
	Dinosaur();

	bool On_Ground();

	void Handle_Event(SDL_Event& e);

	void Move();

	//void RenderDinosaur(SDL_Renderer* gRenderer, SDL_Rect* currentClip, BaseObject &gCharacterTexture);

	int GetPosX();
	int GetPosY();
	int GetStatus();

	void Dinosaur_Status(SDL_Renderer* gRenderer, 
		SDL_Rect* currentClip_RUN, 
		SDL_Rect* currentClip_JUMP, 
		SDL_Rect* currentClip_BOW, 
		BaseObject& gCharacterTexture, 
		BaseObject& gCharacterTexture1);




protected:
	double posX;
	double posY;
	int status;
};

#endif
