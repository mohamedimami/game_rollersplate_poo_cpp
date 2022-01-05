
#include "Win.h"
#include "GameScene.h"


USING_NS_CC;

Scene* Win::createScene()
{
    return Win::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool Win::init()
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
    auto mySprite2 = Sprite::create("back win.png");

    //'visibleSize' et 'origin' nous adaptent la position de notre sprite pour qu'il soit au milieu  :
    mySprite2->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite2);
    auto action = MoveBy::create(3, Point(100, 0));


    //on a ajouté les boutons de notre menu sous formes des images png :
    auto menu_item_1 = MenuItemImage::create("next.png","next.png", CC_CALLBACK_1(Win::Next, this));


    //ici on a créé notre menu qui contient ces boutons et on a les ajuster verticalement
    auto* menu = Menu::create(menu_item_1,  NULL);
    menu->alignItemsVertically();
    this->addChild(menu);


    return true;
}

void Win::Next(cocos2d::Ref* pSender)
{
    //ici on a liée le bouton 'Play' avec une autre scène 'GameScene.h' qui va juste arriver lorsqu'on clique sur ce bouton :
    CCLOG("Next");
    auto scene = GameScene::scene();
    Director::getInstance()->pushScene(TransitionFade::create(1, scene));
}


void Win::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}