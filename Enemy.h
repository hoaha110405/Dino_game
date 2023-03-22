#ifndef ENEMY_H
#define ENEMY_H

#include "BaseObject.h"

#define ENEMY_1 1
#define ENEMY_2 2
#define ENEMY_3 3
#define ENEMY_4 4
#define ENEMY_5 5

class Enemy {
public:
	Enemy();
	~Enemy();

	void Move();

	void render(SDL_Renderer* gRenderer, SDL_Rect* currentClip, BaseObject& gCharacterTexture);

	int GetposX();
	int GetposY();
	int GetTypeEnemy();

	int Random_Enemy();

	void Generate_Enemy(SDL_Renderer* gRenderer,
		SDL_Rect* currentClip_1,
		SDL_Rect* currentClip_2,
		SDL_Rect* currentClip_3,
		BaseObject& gEnemyTexture_1,
		BaseObject& gEnemyTexture_2,
		BaseObject& gEnemyTexture_3,
		BaseObject& gEnemyTexture_4, 
		BaseObject& gEnemyTexture_5);
protected:
	int posX;
	int posY;
	int random_posY;
	int random_type_enemy;
};

#endif