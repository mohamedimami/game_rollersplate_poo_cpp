#pragma once
#include "cocos2d.h"
using namespace cocos2d;
class GameSprite : public Sprite
{
public:
	bool iscolored;
	GameSprite();
	virtual ~GameSprite();
	static GameSprite* gameSpriteinit();
	void changecolor(Color3B _color);

};
