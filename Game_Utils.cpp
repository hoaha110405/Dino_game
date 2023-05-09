#include "Game_Utils.h"

bool CheckColission(Dinosaur dinosaur,
	SDL_Rect* dinosaur_clip,
	Enemy enemy,
	SDL_Rect* enemy_clip,
	int status,
	int type_enemy)
{
	bool collide = false;

	int TRASH_PIXEL_1 = 15;
	int TRASH_PIXEL_2 = 30;
	int TRASH_PIXEL_3 = 15; 

	int left_a = dinosaur.GetPosX();
	int right_a = dinosaur.GetPosX() + dinosaur_clip->w;
	int top_a = dinosaur.GetPosY();
	int bottom_a = dinosaur.GetPosY() + dinosaur_clip->h;

	int left_b = enemy.GetposX();
	int right_b = enemy.GetposX() + enemy_clip->w;
	int top_b = enemy.GetposY();
	int bottom_b = enemy.GetposY() + enemy_clip->h;

	//check
	switch (type_enemy)
	{
		case ENEMY_1:
		{
			if (right_a - TRASH_PIXEL_1 >= left_b && left_a + TRASH_PIXEL_2 <= right_b)
			{
				if (bottom_a - TRASH_PIXEL_3 >= top_b){
					return true;
				}
			}
			break;
		}
		case ENEMY_2:
		{
			if (right_a - 12 >= left_b && left_a + 8 <= right_b)
			{
				if (top_a + 27 <= bottom_b && bottom_a-10 >= top_b && status!=BOW) {
					return true;
				}
				else if (status == BOW && top_a + 39 <= bottom_b)
				{
					return true;
				}
			}
			break;
		}
		case ENEMY_3:
		{
			if (right_a - 11 >= left_b && left_a + 38 <= right_b && bottom_a - 12 >= top_b)
			{
				return true;
			}
			break;
		}
		case ENEMY_4:
		{
			if (right_a - 12 >= left_b && left_a + 38 <= right_b && bottom_a - 30 >= top_b)
			{
				return true;
			}
			break;
		}
		case ENEMY_5:
		{
			if (right_a - 20 >= left_b && left_a + 6 <= right_b)
			{
				if (status != BOW) {
					return true;
				}
			}
		}
	}

}

void update_time(int& time)
{
	time += 1;

	if (time % 10 == 0) {
		score += 1;
	}
	if (time >= 10) time = 1;
}

void reset_score()
{
	score = 0;
}

void Draw_Score(TTF_Font* gFont,
	SDL_Renderer* gRenderer)
{
	BaseObject gFont_Score_Texture;

	gFont_Score_Texture.LoadFromRenderedText(to_string(score), gFont, textColor, gRenderer);
	gFont_Score_Texture.Render(PosX_Your_score+130, PosY_Your_score, gRenderer);
}

void Draw_Hight_Score(TTF_Font* gFont,
	SDL_Renderer* gRenderer)
{
	BaseObject gFont_Hight_Score_Texture;

	gFont_Hight_Score_Texture.LoadFromRenderedText(to_string(hight_score_n), gFont, textColor, gRenderer);
	gFont_Hight_Score_Texture.Render(PosX_Hight_score+130, PosY_Hight_score, gRenderer);
}

void Update_hight_score()
{
	string hight_score_s;
	ifstream input("C:\\Users\\FPTShop\\Desktop\\Studio\\DEMO 2\\score\\score.txt");
	input >> hight_score_s;
	int hight_score = atoi(hight_score_s.c_str());
	hight_score_n = hight_score;
	if (score >= hight_score)
	{
		ofstream output("C:\\Users\\FPTShop\\Desktop\\Studio\\DEMO 2\\score\\score.txt");
		output << to_string(score);
	}
}