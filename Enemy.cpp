#include "Enemy.h"

Enemy::Enemy()
{
	posX = rand()%(800+1) + 800;
	posY = GROUND;
	random_posY = rand() % (GROUND-300) + 300;
	random_type_enemy = rand() % 5 + 1;
}

Enemy::~Enemy()
{
	posX = 0;
	posY = 0;
	random_posY=0;
	random_type_enemy = 0;
}

int Enemy::Random_Enemy()
{
	return rand() % 5 + 1;
}

void Enemy::Generate_Enemy(SDL_Renderer* gRenderer,
	SDL_Rect* currentClip_1,
	SDL_Rect* currentClip_2,
	SDL_Rect* currentClip_3,
	BaseObject& gEnemyTexture_1,
	BaseObject& gEnemyTexture_2,
	BaseObject& gEnemyTexture_3,
	BaseObject& gEnemyTexture_4,
	BaseObject& gEnemyTexture_5)
{
	if (random_type_enemy == ENEMY_1) {
		if (posX + 45 <= 0) {
			posX = rand() % (800 + 1) + 800;
			random_type_enemy = Random_Enemy();
		}
		else {
			posX -= 9;
			gEnemyTexture_1.Render(posX, posY, gRenderer, currentClip_1);
		}
	}
	else if (random_type_enemy == ENEMY_2)
	{
		if (posX + 45 <= 0) {
			posX = rand() % (800 + 1) + 800;
			posY = GROUND;
			random_type_enemy = Random_Enemy();
		}
		else {
			posX -= 9;
			posY = random_posY;
			gEnemyTexture_2.Render(posX, posY, gRenderer, currentClip_2);
		}
	}
	else if (random_type_enemy == ENEMY_3)
	{
		if (posX + 45 <= 0) {
			posX = rand() % (800 + 1) + 800;
			random_type_enemy = Random_Enemy();
		}
		else {
			posX -= 7;
			gEnemyTexture_3.Render(posX, posY, gRenderer, NULL);
		}
	}
	else if (random_type_enemy == ENEMY_4)
	{
		if (posX + 45 <= 0) {
			posX = rand() % (800 + 1) + 800;
			random_type_enemy = Random_Enemy();
		}
		else {
			posX -= 7;
			gEnemyTexture_4.Render(posX, posY, gRenderer, NULL);
		}
	}
	else if (random_type_enemy == ENEMY_5)
	{
		if (posX + 45 <= 0) {
			posX = rand() % (800 + 1) + 800;
			random_type_enemy = Random_Enemy();
			posY = GROUND;
		}
		else {
			posY = GROUND - 75;
			posX -= 7;
			gEnemyTexture_5.Render(posX, posY, gRenderer, currentClip_3);
		}
	}
}

void Enemy::render(SDL_Renderer* gRenderer, SDL_Rect* currentClip, BaseObject& gCharacterTexture)
{
	gCharacterTexture.Render(posX, posY, gRenderer, currentClip);
}
int Enemy::GetposX()
{
	return posX;
}


int Enemy::GetposY()
{
	return posY;
}

int Enemy::GetTypeEnemy()
{
	return random_type_enemy;
}