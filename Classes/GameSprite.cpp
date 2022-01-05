#include "GameSprite.h"
GameSprite::GameSprite(void) {
	this->iscolored = false;
};
GameSprite::~GameSprite(void) {

}
GameSprite* GameSprite::gameSpriteinit() {
	auto sprite = new GameSprite();
	sprite->initWithFile("triiiq.png");
	return sprite;
}



void GameSprite::changecolor(Color3B _color) {
	this->setColor(_color);
	this->iscolored = true;
}