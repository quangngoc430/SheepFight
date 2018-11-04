#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"

USING_NS_CC;

Scene* SceneNewGame::createScene()
{
	return SceneNewGame::create();
}

bool SceneNewGame::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto sprite = Sprite::create("galaxy1.jpg");
	
	sprite->setPosition(visibleSize / 2);
	this->addChild(sprite, 0);

	//---------------------------
	// Button
	//---------------------------

	auto closeItem1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _MENU::createScene()));
	});
	closeItem1->setPosition(visibleSize.width - closeItem1->getContentSize().width / 2, visibleSize.height - closeItem1->getContentSize().height / 2);
	
	auto sheep1 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	auto sheep2 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	auto sheep3 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	sheep1->setPosition(closeItem1->getContentSize().width * 2, visibleSize.height - closeItem1->getContentSize().height / 2);
	sheep2->setPosition(sheep1->getPosition() + (Vec2(50, 0)));
	sheep3->setPosition(sheep2->getPosition() + (Vec2(50, 0)));

	auto sheep4 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	auto sheep5 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	auto sheep6 = MenuItemImage::create("sheep.png", "click_sheep.png", [](Ref *event) {});
	sheep4->setPosition(closeItem1->getPosition() - (Vec2(50, 0)));
	sheep5->setPosition(sheep4->getPosition() - (Vec2(50, 0)));
	sheep6->setPosition(sheep5->getPosition() - (Vec2(50, 0)));

	auto menuImage = Menu::create(closeItem1, sheep1, sheep2, sheep3, sheep4, sheep5, sheep6, nullptr);
	menuImage->setPosition(Vec2::ZERO);
	addChild(menuImage);
	//---------------------------------
	// Sheep run
	//---------------------------------
	auto _sheep1 = Sprite::create("sheep.png");
	auto _sheep2 = Sprite::create("sheep.png");
	auto _sheep3 = Sprite::create("sheep.png");
	auto _sheep4 = Sprite::create("sheep.png");
	auto _sheep5 = Sprite::create("sheep.png");
	_sheep1->setPosition(mLane1);
	_sheep2->setPosition(mLane2);
	_sheep3->setPosition(mLane3);
	_sheep4->setPosition(mLane4);
	_sheep5->setPosition(mLane5);
	this->addChild(_sheep1, 0);
	this->addChild(_sheep2, 0);
	this->addChild(_sheep3, 0);
	this->addChild(_sheep4, 0);
	this->addChild(_sheep5, 0);


	// Action
	auto moveBy1 = MoveBy::create(12, Vec2(600, 0));
	auto moveBy2 = MoveBy::create(10, Vec2(600, 0));
	auto moveBy3 = MoveBy::create(8, Vec2(600, 0));
	auto moveBy4 = MoveBy::create(6, Vec2(600, 0));
	auto moveBy5 = MoveBy::create(4, Vec2(600, 0));
	_sheep1->runAction(moveBy1);
	_sheep2->runAction(moveBy2);
	_sheep3->runAction(moveBy3);
	_sheep4->runAction(moveBy4);
	_sheep5->runAction(moveBy5);

	return true;
}