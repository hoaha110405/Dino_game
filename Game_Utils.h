#ifndef GAME_UTILS_H
#define GAME_UTILS_H

#include "Dinosaur.h"
#include "Enemy.h"

static int hight_score_n = 0;
static int score = 0;

bool CheckColission(Dinosaur dinosaur,
	SDL_Rect* dinosaur_clip,
	Enemy enemy,
	SDL_Rect* enemy_clip,
	int status,
	int type_enmy);

void update_time(int &time);

void Draw_Score(TTF_Font* gFont,
	SDL_Renderer* gRenderer);

void Draw_Hight_Score(TTF_Font* gFont,
	SDL_Renderer* gRenderer);

void Update_hight_score();

void reset_score();

#endif