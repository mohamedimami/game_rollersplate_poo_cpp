#ifndef __WIN_H__
#define __WIN_H__

#include "cocos2d.h"

class Win : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(Win);

    //on a crée ce sprite 'mySprite2' qui contient une image 'you win'
    cocos2d::Sprite* mySprite2;

    //ici on a déclaré ce bouton qui nous passe au niveau suivant
    void Next(Ref* pSender);


};

#endif // __HELLOWORLD_SCENE_H__