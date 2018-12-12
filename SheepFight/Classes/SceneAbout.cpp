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
	auto s = Director::getInstance()->getVisibleSize();
	
	auto sprite = Sprite::create();

	auto design = Label::createWithTTF("Design \n Nguyen Hoang \n Nguyen Phuoc Hong Hai", "fonts/Marker-Felt.ttf", 30);
	auto coder = Label::createWithTTF("Coder \n Le Van Viet Hung \n Bui Lam Quang Ngoc", "fonts/Marker-Felt.ttf", 30);
	
	design->setAlignment(cocos2d::TextHAlignment::CENTER);
	coder->setAlignment(cocos2d::TextHAlignment::CENTER);


	sprite->setPosition(400,240);

	this->addChild(sprite, 0);


	// sprite 1
	ccBezierConfig bezier;
	bezier.controlPoint_1 = Vec2(0, s.height / 2);
	bezier.controlPoint_2 = Vec2(300, -s.height / 2);
	bezier.endPosition = Vec2(400, 300);
	
	// sprite 2
	ccBezierConfig bezier2;
	bezier2.controlPoint_1 = Vec2(100, s.height / 2);
	bezier2.controlPoint_2 = Vec2(200, -s.height / 2);
	bezier2.endPosition = Vec2(400, 150);

	auto bezierTo1 = BezierTo::create(2, bezier);
	auto bezierTo2 = BezierTo::create(2, bezier2);

	design->setPosition(200, 160);
	coder->setPosition(400, 160);

	//design->runAction(rep);
	coder->runAction(bezierTo1);
	design->runAction(bezierTo2);

	addChild(design);
	addChild(coder);



	// Add button back
	auto closeItem1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _MENU::createScene()));
	});
	closeItem1->setPosition(s.width - closeItem1->getContentSize().width / 2, s.height - closeItem1->getContentSize().height / 2);

	auto menuImage = Menu::create(closeItem1, nullptr);
	menuImage->setPosition(Vec2::ZERO);
	addChild(menuImage);
	return true;
}