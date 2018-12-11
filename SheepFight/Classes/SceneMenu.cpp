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
	auto newGame = ui::Button::create("Play_unclick.png", "Play_clicked.png", "Play_clicked.png");
	auto about = ui::Button::create("About_unclick.png", "About_clicked.png", "About_clicked.png");
	auto exit = ui::Button::create("Exit_unclick.png", "Exit_clicked.png", "Exit_clicked.png");

	newGame->addTouchEventListener([](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _NEW_GAME::createScene()));

			break;
		default:
			break;
		}
	});
	about->addTouchEventListener([](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:		
			Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _ABOUT::createScene()));
			break;
		default:
			break;
		}
	});
	exit->addTouchEventListener([](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			Director::getInstance()->end();
			break;
		default:
			break;
		}
	});


	newGame->setPosition(Vec2(420, 230));
	about->setPosition(newGame->getPosition() - Vec2(0, 70));
	exit->setPosition(about->getPosition() - Vec2(-10, 70));

	addChild(newGame);
	addChild(about);
	addChild(exit);

	return true;
}