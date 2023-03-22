#ifndef BUTTON_H
#define BUTTON_H

#include "CommonFunc.h"

enum LButtonSprite
{
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER_MOTION = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Button {
public:
	Button();

	LButtonSprite mCurrentSprite;

	void setPosition(int x, int y);

	void handleEvent(SDL_Event* e);

protected:
	SDL_Point mPosition;
};

#endif
