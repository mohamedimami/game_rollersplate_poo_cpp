#ifndef __GAME_OVER_H__
#define __GAME_OVER_H__

#include "cocos2d.h"

class GameOver : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createSceneOver();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameOver);

    //on a crée ce sprite 'mySprite3' qui contient une image 'you win'
    cocos2d::Sprite* mySprite3;



};

#endif // __HELLOWORLD_SCENE_H__