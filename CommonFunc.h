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

using namespace std;

const double SCREEN_WIDTH = 800;
const double SCREEN_HEIGHT = 454;
const double WALKING_ANIMATION_FRAMES = 5;

static SDL_Window* gWindow = NULL;
static SDL_Renderer* gRenderer = NULL;
static SDL_Event* gEvent = NULL;

static double NUMBER_OF_STEP = 10;

#define GROUND 380
#define JUMP_SPEED 1
#define BUTTON_WIDTH 50
#define BUTTON_HEIGHT 27


#endif

