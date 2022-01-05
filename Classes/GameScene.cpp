#include "GameScene.h"
#include "GameSprite.h"
#include "Header.h"
#include "Win.h"
#include "GameOver.h"


int GameScene::count = 0;

//l'initialisation du mouvement de balle
GameScene::GameScene() {
	ismoving = false;
	_direction_x = 0;
	_direction_y = 0;
}
GameScene::~GameScene() {

}
void GameScene::update(float dt) {
	if (ismoving == true) {
		_ball->setPosition(_ball->getPosition().x + _direction_x, _ball->getPosition().y + _direction_y);
	}
	for (auto _sprites : _collidsprites) {
		if (_direction_x == 0 && _direction_y == 1) {
			if (_ball->getPositionX() == _sprites->getPositionX() && _ball->getPositionY() == _sprites->getPositionY() - 10) {
				ismoving = false;
			}
		}
		if (_direction_x == 0 && _direction_y == -1) {
			if (_ball->getPositionX() == _sprites->getPositionX() && _ball->getPositionY() == _sprites->getPositionY() + 10) {
				ismoving = false;
			}
		}
		if (_direction_x == 1 && _direction_y == 0) {
			if (_ball->getPositionX() == _sprites->getPositionX() - 10 && _ball->getPositionY() == _sprites->getPositionY()) {
				ismoving = false;
			}
		}
		if (_direction_x == -1 && _direction_y == 0) {
			if (_ball->getPositionX() == _sprites->getPositionX() + 10 && _ball->getPositionY() == _sprites->getPositionY()) {
				ismoving = false;
			}
		}

	}
	for (auto _mysprites : _spritevector) {
		//ici lorqsue la balle se déplace , le couleur se change en arrière de la balle :
		if (_ball->getPosition() == _mysprites->getPosition() && _mysprites->iscolored == false) {
			_mysprites->changecolor(Color3B(139, 139, 0)); //ici on a précisé le couleur qui va changer
			laith++;
		}
	}

	//ici lorsque le chemin est totalemnt coloré , la scene va changer vers le scene de 'Win' qui va nous passer au niveau suivant : 
	if (laith == end) {
		count++;
		auto scene = Scene::create();
		auto layer = Win::create();
		scene->addChild(layer);
		director->getInstance()->replaceScene(scene);

		if (count == 3) {
			auto scene = Scene::create();
			auto layer = GameOver::create();
			scene->addChild(layer);
			director->getInstance()->replaceScene(scene);
		}
		
	}
}

//ici on a déclaré les fonctions des événements lorsqu'on appuie sure les boutons du clavier :
EventListenerKeyboard* GameScene::onKeyBoardEvent() {
	auto listener = EventListenerKeyboard::create();
	listener->onKeyPressed = [=](EventKeyboard::KeyCode _keycode, Event* event) {
		if (!ismoving) {
			switch (_keycode) {
			case EventKeyboard::KeyCode::KEY_UP_ARROW:
				_direction_y = 1;
				_direction_x = 0;
				ismoving = true;
				break;
			case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
				_direction_y = -1;
				_direction_x = 0;
				ismoving = true;
				break;
			case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
				_direction_x = -1;
				_direction_y = 0;
				ismoving = true;
				break;
			case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
				_direction_x = 1;
				_direction_y = 0;
				ismoving = true;
				break;
			}
		}
	};
	return listener;
}
// la creation de la scene : 
Scene* GameScene::scene() {
	auto scene = Scene::create();
	auto layer = GameScene::create();
	scene->addChild(layer);
	return scene;
}

bool GameScene::init() {

	if (!Layer::init()) {
		return false;
	}

	
	//cette variable 'count' s'incrémente par 1 et sa rôle est de passer d'un niveau à un autre :
	
	if (count == 0) {

		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		//chaque niveau a un sprite unique :
		auto mySprite = Sprite::create("level1back.png");

		mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
		this->addChild(mySprite);

		end = 1664;
		auto _array = arraylevel1;
		for (auto i = 0; i <= 8; i++) { // contrôler le chemin de la balle verticalement
			for (auto j = 0; j <= 13; j++) { // contrôler le chemin de la balle horizontalement
				for (auto x = 0; x < 32; x++) { //32 est le nombre de blocs
					if ((i == _array[x][0] && j == _array[x][1]) || i == 0 || i == 8 || j == 0 || j == 13) {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10)); //la position de la map 
						_sprite->setColor(Color3B(69, 139, 0)); //la couleur verte de blocs
						_collidsprites.pushBack(_sprite);
						this->addChild(_sprite);
						break;
					}
					else {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10));
						_sprite->setColor(Color3B(255, 255, 0)); //la couleur jaune est le couleur du chemin avant qu'il se colore lorsque la balle se déplace
						_spritevector.pushBack(_sprite);
						this->addChild(_sprite);
					}
				}
			}
		}
	}




	if (count == 1) {


		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto mySprite = Sprite::create("lev2back.png");

		mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
		this->addChild(mySprite);


		end = 1664;
		auto _array = arraylevel2;
		for (auto i = 0; i <= 8; i++) {
			for (auto j = 0; j <= 13; j++) {
				for (auto x = 0; x < 32; x++) {
					if ((i == _array[x][0] && j == _array[x][1]) || i == 0 || i == 8 || j == 0 || j == 13) {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10));
						_sprite->setColor(Color3B(69, 139, 0));
						_collidsprites.pushBack(_sprite);
						this->addChild(_sprite);
						break;
					}
					else {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10));
						_sprite->setColor(Color3B(255, 255, 0));
						_spritevector.pushBack(_sprite);
						this->addChild(_sprite);
					}
				}
			}
		}
	}






	if (count == 2) {


		auto visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto mySprite = Sprite::create("lev3back.png");

		mySprite->setPosition(Point((visibleSize.width / 2) + origin.x, (visibleSize.height / 2) + origin.y));
		this->addChild(mySprite);

		end = 1568;
		auto _array = arraylevel3;
		for (auto i = 0; i <= 8; i++) {
			for (auto j = 0; j <= 13; j++) {
				for (auto x = 0; x < 28; x++) {
					if ((i == _array[x][0] && j == _array[x][1]) || i == 0 || i == 8 || j == 0 || j == 13) {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10));
						_sprite->setColor(Color3B(69, 139, 0));
						_collidsprites.pushBack(_sprite);
						this->addChild(_sprite);
						break;
					}
					else {
						auto _sprite = GameSprite::gameSpriteinit();
						_sprite->setPosition(Vec2(125 + i * 10, 18 + j * 10));
						_sprite->setColor(Color3B(255, 255, 0));
						_spritevector.pushBack(_sprite);
						this->addChild(_sprite);
					}
				}
			}
		}
	}
	
	


	_ball = Sprite::create("mario.png"); //la sprite de notre balle
	_ball->setPosition(Vec2(135, 28)); //la position de la balle dans la map (elle est liée par la position de la map (même coordonnées))
	this->addChild(_ball);
	this->scheduleUpdate();
	auto eventListener = onKeyBoardEvent();
	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(eventListener, _ball);
	return true;
}