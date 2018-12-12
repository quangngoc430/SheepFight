#include "SceneAbout.h"
#include "Defines.h"
#include "SceneMenu.h"

USING_NS_CC;

Scene* SceneAbout::createScene()
{
	return SceneAbout::create();
}

bool SceneAbout::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto sprite = Sprite::create();

	auto design = Label::createWithTTF("Design \n Nguyen Hoang \n Nguyen Phuoc Hong Hai", "fonts/Marker-Felt.ttf", 30);
	auto coder = Label::createWithTTF("Coder \n Le Van Viet Hung \n Bui Lam Quang Ngoc", "fonts/Marker-Felt.ttf", 30);
	
	design->setAlignment(cocos2d::TextHAlignment::CENTER);
	coder->setAlignment(cocos2d::TextHAlignment::CENTER);

	design->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + 250));
	coder->setPosition(Vec2(visibleSize.width / 2, visibleSize.height + 100));

	addChild(design);
	addChild(coder);

	auto moveDesign = MoveBy::create(2, Vec2(0, -400));
	auto moveCoder = MoveBy::create(2, Vec2(0, -400));
	design->runAction(moveDesign);
	coder->runAction(moveCoder);
	
	sprite->setPosition(400,240);

	this->addChild(sprite, 0);

	// Add button back
	auto closeItem1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _MENU::createScene()));
	});
	closeItem1->setPosition(visibleSize.width - closeItem1->getContentSize().width / 2, visibleSize.height - closeItem1->getContentSize().height / 2);

	auto menuImage = Menu::create(closeItem1, nullptr);
	menuImage->setPosition(Vec2::ZERO);
	addChild(menuImage);
	return true;
}