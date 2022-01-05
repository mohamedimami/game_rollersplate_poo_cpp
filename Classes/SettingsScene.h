#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "cocos2d.h"

class SettingsScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(SettingsScene);

    //on a cr�e un sprite 'mySprite' qui contient l'arri�re-plan de notre scene
    cocos2d::Sprite* mySprite;

    //ici on a d�clar� les �l�ments de notre scene de param�tres
    /*void Sound(Ref* pSender);
    void Music(Ref* pSender);*/
    void GoBack(Ref* pSender);

    
};

#endif // __SETTINGS_SCENE_H__