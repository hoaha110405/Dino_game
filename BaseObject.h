#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"

class BaseObject
{
public:
	BaseObject();

	~BaseObject();

	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);

	bool LoadFromRenderedText(std::string textureText, TTF_Font* gFont, SDL_Color textColor, SDL_Renderer* gRenderer);

	void free();

	void Render(int x, int y, SDL_Renderer* gRenderer=NULL, SDL_Rect* clip= nullptr);

	int getWidth();
	int getHeight();

protected:
	SDL_Texture* mTexture;

	int mWidth;
	int mHeight;
};

#endif // !BASE_OBJECT_H
