
#include "HelloWorldScene.h"
#include "SettingsScene.h"


USING_NS_CC;

Scene* SettingsScene::createScene()
{
    return SettingsScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool SettingsScene::init()
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
    auto mySprite = Sprite::create("music.png");

    //'visibleSize' et 'origin' nous adaptent la position de notre sprite pour qu'il soit au milieu  :
    mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite);
    auto action = MoveBy::create(3, Point(100, 0));

    //on a ajouté les boutons de notre menu sous formes des images png :
    /*auto menu_item_1 = MenuItemFont::create("Sound", CC_CALLBACK_1(SettingsScene::Sound, this));
    auto menu_item_2 = MenuItemFont::create("Music", CC_CALLBACK_1(SettingsScene::Music, this));*/
    auto menu_item_1 = MenuItemImage::create("gobaks.png","gobaks.png",  CC_CALLBACK_1(SettingsScene::GoBack, this));

    //ici on a créé notre menu qui contient ces boutons et on a les ajuster verticalement
    auto* menu = Menu::create(menu_item_1, NULL);
    menu->alignItemsVertically();
    this->addChild(menu);


    return true;
}

//void SettingsScene::Sound(cocos2d::Ref* pSender)
//{
//    CCLOG("Sound");
//    
//}
//
//void SettingsScene::Music(cocos2d::Ref* pSender)
//{
//    CCLOG("Music");
//}

void SettingsScene::GoBack(cocos2d::Ref* pSender)
{
    Director::getInstance()->popScene();
}


void SettingsScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}