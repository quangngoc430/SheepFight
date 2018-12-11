#include "SceneMenu.h"
#include "Defines.h"
#include "SceneNewGame.h"
#include "SceneAbout.h"
#include "SceneOptions.h"
#include "Sheep.h"

USING_NS_CC;

Sheep *sheep;

Scene* SceneMenu::createScene()
{
	return SceneMenu::create();
}

bool SceneMenu::init()
{
	if (!Scene::init())
	{
		return false;
	}
	auto visibleSize = Director::getInstance()->getVisibleSize();
	
	auto sprite = Sprite::create(IMG_MENU);
	
	sprite->setPosition(visibleSize / 2);
	this->addChild(sprite, 0);
	
	// Menu String

	auto newGame = MenuItemFont::create("New Game", [](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _NEW_GAME::createScene()));
	});
	auto options = MenuItemFont::create("Options", [](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _OPTIONS::createScene()));
	});
	auto about = MenuItemFont::create("About", [](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _ABOUT::createScene()));
	});
	auto quit = MenuItemFont::create("Quit", [](Ref *event) {
		Director::getInstance()->end();
	});

	newGame->setPosition(visibleSize.width / 2, visibleSize.height - 200);
	options->setPosition(newGame->getPosition() - Vec2(0, 50));
	about->setPosition(options->getPosition() - Vec2(0, 50));
	quit->setPosition(about->getPosition() - Vec2(0, 50));

	auto menuString = Menu::create(newGame, options, about, quit, nullptr);
	menuString->setPosition(Vec2::ZERO);
	addChild(menuString);

	return true;
}