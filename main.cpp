#include "CommonFunc.h"
#include "BaseObject.h"
#include "Dinosaur.h"
#include "main.h"
#include "Enemy.h"
#include "Button.h"
#include "Game_Utils.h"

BaseObject gBackgroundTexture;
BaseObject gDinosaurTexture;
BaseObject gDinosaur_BOW_Texture;
BaseObject gEnemyTexture_1;
BaseObject gEnemyTexture_2;
BaseObject gEnemyTexture_3;
BaseObject gEnemyTexture_4;
BaseObject gEnemyTexture_5;
BaseObject gMenuTexture;
BaseObject gPlayButtonTexture;
//BaseObject gHelpButtonTexture;
BaseObject gExitButtonTexture;
BaseObject gFont_Your_score_Texture;
BaseObject gFont_Score_Texture;
BaseObject gFont_Hight_score_Texture;
BaseObject gGameoverTexture;

SDL_Rect gDinosaurClip[5];
SDL_Rect gDinosaur_BOW_CLIP[5];
SDL_Rect gEnemyClip_1[5];
SDL_Rect gEnemyClip_2[5];
SDL_Rect gEnemyClip_3[5];
SDL_Rect gPlayButton[2];
//SDL_Rect gHelpButton[2];
SDL_Rect gExitButton[2];

Dinosaur dinosaur;

Button PlayButton;
//Button HelpButton;
Button ExitButton;

Mix_Music* gMusic = NULL;

TTF_Font* gFont = NULL;

bool init()
{
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}

				//Initialize SDL_mixer
				if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
				{
					printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
					success = false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	bool success = true;
	//load menu
	if (!gMenuTexture.loadFromFile("img//bk1.jpg", gRenderer))
	{
		printf("Failed to load bk1.jpg!\n");
		success = false;
		return success;
	}

	// load nut play
	if (!gPlayButtonTexture.loadFromFile("img//button_play.png", gRenderer))
	{
		printf("Failed to load button_play.png!\n");
		success = false;
		return success;
	}
	else
	{
		for (int i = 0; i < 2; i++) {
			gPlayButton[i].x = i* BUTTON_WIDTH;
			gPlayButton[i].y = 0;
			gPlayButton[i].w = BUTTON_WIDTH;
			gPlayButton[i].h = BUTTON_HEIGHT;
		}
	}
	PlayButton.setPosition(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220);

	//load nut help
	/*if (!gHelpButtonTexture.loadFromFile("img//button_help.png", gRenderer))
	{
		printf("Failed to load button_help.png!\n");
		success = false;
		return success;
	}
	else
	{
		for (int i = 0; i < 2; i++) {
			gHelpButton[i].x = i * BUTTON_WIDTH;
			gHelpButton[i].y = 0;
			gHelpButton[i].w = BUTTON_WIDTH;
			gHelpButton[i].h = BUTTON_HEIGHT;
		}
	}
	HelpButton.setPosition(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220+BUTTON_HEIGHT+15);*/

	//load nut thoat
	if (!gExitButtonTexture.loadFromFile("img//exit_button.png", gRenderer))
	{
		printf("Failed to load button_exit.png!\n");
		success = false;
		return success;
	}
	else
	{
		for (int i = 0; i < 2; i++) {
			gExitButton[i].x = i * BUTTON_WIDTH;
			gExitButton[i].y = 0;
			gExitButton[i].w = BUTTON_WIDTH;
			gExitButton[i].h = BUTTON_HEIGHT;
		}
	}
	ExitButton.setPosition(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220 + BUTTON_HEIGHT + 15 + BUTTON_HEIGHT + 15);

	//load background game
	if (!gBackgroundTexture.loadFromFile("img//background.jpg",gRenderer))
	{
		printf("Failed to load background.jpg!\n");
		success = false;
		return success;
	}

	//load game over
	if (!gGameoverTexture.loadFromFile("img//game over.png", gRenderer))
	{
		printf("Failed to load game over.png!\n");
		success = false;
		return success;
	}

	//load khung long chay
	if (!gDinosaurTexture.loadFromFile("img//dinosaur.png", gRenderer))
	{
		printf("Failed to load dinosaur.png!\n");
		success = false;
		return success;
	}
	else {
		for (int i = 0; i < 5; i++) {
			gDinosaurClip[i].x = i * DINOSAUR_WIDTH;
			gDinosaurClip[i].y = 0;
			gDinosaurClip[i].w = DINOSAUR_WIDTH;
			gDinosaurClip[i].h = DINOSAUR_HEIGHT;

		}
	}
	//load khung long cui dau
	if (!gDinosaur_BOW_Texture.loadFromFile("img//dinosaur_bow.png", gRenderer)) {
		printf("Failed to load dinosaur_bow.png!\n");
		success = false;
		return success;
	}
	else {
		for (int i = 0; i < 5; i++) {
			gDinosaur_BOW_CLIP[i].x = i * DINOSAUR_WIDTH;
			gDinosaur_BOW_CLIP[i].y = 0;
			gDinosaur_BOW_CLIP[i].w = DINOSAUR_WIDTH;
			gDinosaur_BOW_CLIP[i].h = DINOSAUR_HEIGHT;
		}
	}
	//load enemy1
	if (!gEnemyTexture_1.loadFromFile("img//enemy1.png", gRenderer))
	{
		printf("Failed to load enemy1.png!\n");
		success = false;
		return success;
	}
	else {
		for (int i = 0; i < 5; i++) {
			gEnemyClip_1[i].x = i* DINOSAUR_WIDTH;
			gEnemyClip_1[i].y = 0;
			gEnemyClip_1[i].w = DINOSAUR_WIDTH;
			gEnemyClip_1[i].h = DINOSAUR_HEIGHT;

		}
	}
	//load enemy2
	if (!gEnemyTexture_2.loadFromFile("img//enemy2.png", gRenderer))
	{
		printf("Failed to load enemy2.png!\n");
		success = false;
		return success;
	}
	else {
		for (int i = 0; i <= 2; i++) {
			gEnemyClip_2[i].x = 0;
			gEnemyClip_2[i].y = 0;
			gEnemyClip_2[i].w = ENEMY2_WIDTH;
			gEnemyClip_2[i].h = ENEMY2_HEIGHT;
		}
		for (int i = 3; i <= 4; i++) {
			gEnemyClip_2[i].x = ENEMY2_WIDTH;
			gEnemyClip_2[i].y = 0;
			gEnemyClip_2[i].w = ENEMY2_WIDTH;
			gEnemyClip_2[i].h = ENEMY2_HEIGHT;
		}
	}
	//lload enemy3
	if (!gEnemyTexture_3.loadFromFile("img//enemy3.png", gRenderer))
	{
		printf("Failed to load enemy3.png!\n");
		success = false;
		return success;
	}

	//load enemy4
	if(!gEnemyTexture_4.loadFromFile("img//enemy4.png", gRenderer))
	{
		printf("Failed to load enemy4.png!\n");
		success = false;
		return success;
	}

	//load enemy5
	if (!gEnemyTexture_5.loadFromFile("img//enemy5.png", gRenderer))
	{
		printf("Failed to load enemy5.png!\n");
		success = false;
		return success;
	}
	else {
		for (int i = 0; i < 5; i++) {
			gEnemyClip_3[i].x = i * ENEMY5_WIDTH;
			gEnemyClip_3[i].y = 0;
			gEnemyClip_3[i].w = ENEMY5_WIDTH;
			gEnemyClip_3[i].h = ENEMY5_HEIGHT;
		}
	}

	//Load music
	gMusic = Mix_LoadMUS("sound//all.mp3");
	if (gMusic == NULL)
	{
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}

	//loadFont
	gFont = TTF_OpenFont("font//font.ttf", 18);
	if (gFont == NULL)
	{
		printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		if (!gFont_Your_score_Texture.LoadFromRenderedText("Your score: ",gFont, textColor,gRenderer))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}

		if (!gFont_Hight_score_Texture.LoadFromRenderedText("Hight socre: ",gFont, textColor,gRenderer))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}
	return success;
}

void close()
{
	gBackgroundTexture.free();
	gDinosaur_BOW_Texture.free();
	gDinosaurTexture.free();
	gEnemyTexture_1.free();
	gEnemyTexture_2.free();
	gEnemyTexture_3.free();
	gEnemyTexture_4.free();
	gEnemyTexture_5.free();
	gMenuTexture.free();
	gPlayButtonTexture.free();
	//gHelpButtonTexture.free();
	gExitButtonTexture.free();
	gFont_Your_score_Texture.free();
	gFont_Hight_score_Texture.free();
	gGameoverTexture.free();

	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	Mix_FreeMusic(gMusic);
	gMusic = NULL;

	IMG_Quit();
	SDL_Quit();
}

int main(int argc, char* args[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{	
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			int frame = 0;
			int scrollingOffset = 0;
			bool Menu = true;
			bool Quit_Game = true;
			bool Play_again = true;

			SDL_Event e_mouse;
			SDL_Rect* Current_clip_Dinosaur;
			SDL_Rect* Current_clip_Dinosaur_BOW;
			SDL_Rect* Current_clip_Enemy1;
			SDL_Rect* Current_clip_Enemy2;
			SDL_Rect* Current_clip_Enemy3;


			srand(time(NULL));
			int time = 1;

			Mix_PlayMusic(gMusic, -1);

			while (Menu)
			{
				while (SDL_PollEvent(&e_mouse) != 0)
				{
					//User requests quit
					if (e_mouse.type == SDL_QUIT)
					{
						Menu = false;
					}
					PlayButton.handleEvent(&e_mouse);
					//HelpButton.handleEvent(&e_mouse);
					ExitButton.handleEvent(&e_mouse);
				}


				SDL_RenderClear(gRenderer);

				/////////////
				gMenuTexture.Render(0, 0, gRenderer);

				SDL_Rect* CurrentClip_Play = &gPlayButton[PlayButton.mCurrentSprite];
				gPlayButtonTexture.Render(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220, gRenderer, CurrentClip_Play);

				//SDL_Rect* CurrentClip_Help = &gHelpButton[HelpButton.mCurrentSprite];
				//gHelpButtonTexture.Render(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220 + BUTTON_HEIGHT + 15, gRenderer, CurrentClip_Help);

				SDL_Rect* CurrentClip_Exit = &gExitButton[ExitButton.mCurrentSprite];
				gExitButtonTexture.Render(SCREEN_WIDTH / 2 - BUTTON_WIDTH / 2, 220 + BUTTON_HEIGHT + 15 + BUTTON_HEIGHT + 15, gRenderer, CurrentClip_Exit);

				SDL_RenderPresent(gRenderer);
				SDL_Delay(50);
				if (PlayButton.mCurrentSprite == 3)
				{
					Menu=false;
					Quit_Game = false;
				}
				else if (ExitButton.mCurrentSprite == 3)
				{
					Menu = false;
					Play_again = false;
				}
			}

			while (Play_again)
			{
				SDL_Event e;
				Enemy enemy_first;
				Enemy enemy_second;
				Enemy enemy_third;

				reset_score();

				while (!Quit_Game)
				{
					update_time(time);

					Current_clip_Dinosaur = &gDinosaurClip[frame];
					Current_clip_Dinosaur_BOW = &gDinosaur_BOW_CLIP[frame];
					Current_clip_Enemy1 = &gEnemyClip_1[4 - frame];
					Current_clip_Enemy2 = &gEnemyClip_2[frame];
					Current_clip_Enemy3 = &gEnemyClip_3[frame];

					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							Quit_Game = true;
						}
						dinosaur.Handle_Event(e);						
					}

					frame++;
					scrollingOffset -= 2;

					if (frame > 4)frame = 0;

					SDL_RenderClear(gRenderer);


					if (scrollingOffset < -800)
					{
						scrollingOffset = 0;
					}
					//background
					gBackgroundTexture.Render(scrollingOffset, 0, gRenderer);
					gBackgroundTexture.Render(scrollingOffset + 800, 0, gRenderer);

					//dinosaur
					dinosaur.Dinosaur_Status(gRenderer, Current_clip_Dinosaur, &gDinosaurClip[2], Current_clip_Dinosaur_BOW, gDinosaurTexture, gDinosaur_BOW_Texture);

					//Enemy
					enemy_first.Generate_Enemy(gRenderer,
						Current_clip_Enemy1,
						Current_clip_Enemy2,
						Current_clip_Enemy3,
						gEnemyTexture_1,
						gEnemyTexture_2,
						gEnemyTexture_3,
						gEnemyTexture_4,
						gEnemyTexture_5);

					enemy_second.Generate_Enemy(gRenderer,
						Current_clip_Enemy1,
						Current_clip_Enemy2,
						Current_clip_Enemy3,
						gEnemyTexture_1,
						gEnemyTexture_2,
						gEnemyTexture_3,
						gEnemyTexture_4,
						gEnemyTexture_5);

					enemy_third.Generate_Enemy(gRenderer,
						Current_clip_Enemy1,
						Current_clip_Enemy2,
						Current_clip_Enemy3,
						gEnemyTexture_1,
						gEnemyTexture_2,
						gEnemyTexture_3,
						gEnemyTexture_4,
						gEnemyTexture_5);


					//reder score
					gFont_Your_score_Texture.Render(PosX_Your_score, PosY_Your_score, gRenderer);
					Draw_Score(gFont, gRenderer);
					gFont_Hight_score_Texture.Render(PosX_Hight_score, PosY_Hight_score, gRenderer);
					Draw_Hight_Score(gFont, gRenderer);
					Update_hight_score();

					//va cham va die
					if (CheckColission(dinosaur,
						Current_clip_Dinosaur,
						enemy_first,
						Current_clip_Enemy1,
						dinosaur.GetStatus(),
						enemy_first.GetTypeEnemy()
					) == true) {
						Quit_Game = true;
					}
					if (CheckColission(dinosaur,
						Current_clip_Dinosaur,
						enemy_second,
						Current_clip_Enemy2,
						dinosaur.GetStatus(),
						enemy_second.GetTypeEnemy()
					) == true) {
						Quit_Game = true;
					}
					if (CheckColission(dinosaur,
						Current_clip_Dinosaur,
						enemy_third,
						Current_clip_Enemy3,
						dinosaur.GetStatus(),
						enemy_third.GetTypeEnemy()
					) == true) {
						Quit_Game = true;
					}

					if (Quit_Game)
					{
						gGameoverTexture.Render(SCREEN_WIDTH/2-216/2, SCREEN_HEIGHT/2, gRenderer);
					}

					SDL_RenderPresent(gRenderer);
					SDL_Delay(35);
				}
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						Quit_Game = true;
					}
					else if (e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == 13)
							Quit_Game = false;
					}
					//gGameoverTexture.Render(0, 0, gRenderer);
				}
			}
		}
	}
	close();
	return 0;
}