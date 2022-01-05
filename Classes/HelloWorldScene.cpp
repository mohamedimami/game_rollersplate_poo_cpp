#include "HelloWorldScene.h"
#include "GameScene.h"
#include "SettingsScene.h"
#include "GameOver.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
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
    auto mySprite = Sprite::create("back ground2.png");

    //'visibleSize' et 'origin' nous adaptent la position de notre sprite pour qu'il soit au milieu  :
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite);

    auto action = MoveBy::create(3, Point(100, 0));

    //on a ajouté les boutons de notre menu sous formes des images png :
    auto menu_item_1 = MenuItemImage::create("play.png", "play.png", CC_CALLBACK_1(HelloWorld::Play, this));
    auto menu_item_2 = MenuItemImage::create("settings.png", "settings.png", CC_CALLBACK_1(HelloWorld::Settings, this));
    auto menu_item_3 = MenuItemImage::create("help.png", "help.png", CC_CALLBACK_1(HelloWorld::Help, this));

    //ici on a créé notre menu qui contient ces boutons et on a les ajuster verticalement
    auto* menu = Menu::create(menu_item_1, menu_item_2, menu_item_3, NULL);
    menu->alignItemsVertically();
    this->addChild(menu);


    return true;
}

void HelloWorld::Play(cocos2d::Ref* pSender)
{
    //ici on a liée le bouton 'Play' avec une autre scène 'GameScene.h' qui va juste arriver lorsqu'on clique sur ce bouton :
    CCLOG("Play");
    auto scene = GameScene::scene();
    Director::getInstance()->pushScene(TransitionFade::create(1, scene));
}

void HelloWorld::Settings(cocos2d::Ref* pSender)
{
    //ici on a liée le bouton 'Settings' avec une autre scène 'SettingsScene.h' qui va juste arriver lorsqu'on clique sur ce bouton :
    CCLOG("Settings");
    auto scene = SettingsScene::createScene();
    Director::getInstance()->pushScene(TransitionFade::create(1, scene));
}

void HelloWorld::Help(cocos2d::Ref* pSender)
{
    CCLOG("Help");
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}