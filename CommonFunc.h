#ifndef FILE_COMMONFUNC_H_
#define FILE_COMMONFUNC_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int SCREEN_WIDTH = 800;
const double SCREEN_HEIGHT = 454;
const double WALKING_ANIMATION_FRAMES = 5;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static SDL_Event* gEvent = NULL;
static SDL_Color textColor = { 255, 255, 0 };

static double NUMBER_OF_STEP = 10;

#define GROUND 380
#define JUMP_SPEED 1
#define BUTTON_WIDTH 50
#define BUTTON_HEIGHT 27

#define DINOSAUR_WIDTH 45
#define DINOSAUR_HEIGHT 45

#define ENEMY2_WIDTH 87/2
#define ENEMY2_HEIGHT 25

#define ENEMY5_WIDTH 43.2
#define ENEMY5_HEIGHT 90

#define PosX_Your_score 50
#define PosY_Your_score 50
#define PosX_Hight_score 50
#define PosY_Hight_score 75



#endif

