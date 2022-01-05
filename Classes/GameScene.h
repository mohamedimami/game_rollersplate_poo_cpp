#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "GameSprite.h"

using namespace cocos2d;

//ce fichier présente la scene de notre jeu

class GameScene : public Layer
{
	//ici on a déclaré les attributs privées :
private:
	Vector<GameSprite*> _spritevector;
	Vector<GameSprite*> _collidsprites;
	bool ismoving = false;
	int _direction_x = 0;
	int _direction_y = 0;
	int end;
	int laith = 0;

	//on a déclaré les attributs publiques :
public:
	static int count;
		Director* director;
	GameScene();
	virtual ~GameScene();
	Sprite* _ball;
	bool init();
	static Scene* scene();
	CREATE_FUNC(GameScene);
	EventListenerKeyboard* onKeyBoardEvent();
	void update(float dt);
	cocos2d::Sprite* mySprite;


};




#endif // __GAME_SCENE_H__