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
	
	auto sprite = Sprite::create("galaxy3.jpg");
	
	sprite->setPosition(visibleSize / 2);

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