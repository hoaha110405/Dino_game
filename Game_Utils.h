#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "Dinosaur.h"
#include "Enemy.h"

static int time_run = 0;

bool CheckColission(Dinosaur dinosaur,
	SDL_Rect* dinosaur_clip,
	Enemy enemy,
	SDL_Rect* enemy_clip,
	int status,
	int type_enmy);

void update_time(int &time);

int Random_Type_Enemy();

#endif