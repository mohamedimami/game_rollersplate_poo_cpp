#include "GameOver.h"
#include "GameScene.h"
#include "HelloWorldScene.h"


USING_NS_CC;

Scene* GameOver::createSceneOver()
{
    return GameOver::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameOver::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    //Déclaration de 'visibleSize' et 'origin' :
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //on a ajouté cette image qui présente notre arrière-plan :
    auto mySprite3 = Sprite::create("gameover.png");

    //'visibleSize' et 'origin' nous adaptent la position de notre sprite pour qu'il soit au milieu  :
    mySprite3->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite3);
    auto action = MoveBy::create(3, Point(100, 0));


    


    return true;
}


void GameOver::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}