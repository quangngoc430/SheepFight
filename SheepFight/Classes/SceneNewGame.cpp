#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"
#include "ui/CocosGUI.h"
#include "Sheep.h"
#include "Space.h"

Sheep *space1;

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

	////---------------------------------
	//// Add button back
	////---------------------------------
	auto closeItem1 = MenuItemImage::create("CloseNormal.png", "CloseSelected.png",
		[](Ref *event) {
		Director::getInstance()->replaceScene(TransitionFlipX::create(0.5, _MENU::createScene()));
	});
	closeItem1->setPosition(visibleSize.width - closeItem1->getContentSize().width / 2, visibleSize.height - closeItem1->getContentSize().height / 2);

	auto menuImage = Menu::create(closeItem1, nullptr);
	menuImage->setPosition(Vec2::ZERO);
	addChild(menuImage);

	////---------------------------------
	//// Add Sheep random
	////---------------------------------
	


	auto sheep1 = Sprite::create(IMG_SHEEP);
	auto sheep2 = Sprite::create(IMG_SHEEP);
	auto sheep3 = Sprite::create(IMG_SHEEP);
	sheep1->setPosition(closeItem1->getContentSize().width * 2, visibleSize.height - closeItem1->getContentSize().height / 2);
	sheep2->setPosition(sheep1->getPosition() + (Vec2(50, 0)));
	sheep3->setPosition(sheep2->getPosition() + (Vec2(50, 0)));

	auto sheep4 = Sprite::create(IMG_SHEEP);
	auto sheep5 = Sprite::create(IMG_SHEEP);
	auto sheep6 = Sprite::create(IMG_SHEEP);
	sheep4->setPosition(closeItem1->getPosition() - (Vec2(50, 0)));
	sheep5->setPosition(sheep4->getPosition() - (Vec2(50, 0)));
	sheep6->setPosition(sheep5->getPosition() - (Vec2(50, 0)));

	this->addChild(sheep1, 0);
	this->addChild(sheep2, 0);
	this->addChild(sheep3, 0);
	this->addChild(sheep4, 0);
	this->addChild(sheep5, 0);
	this->addChild(sheep6, 0);

	

	auto btn = ui::Button::create("go0.png", "go1.png", "go0.png");
	btn->setPosition(mLane1 + Vec2(300, 0));
	btn->addTouchEventListener([&, sheep1, sheep2, sheep3](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{

			auto action = MoveBy::create(1, Vec2(50, 0));
			auto action1 = TargetedAction::create(sheep1, action);
			auto action2 = TargetedAction::create(sheep2, action->clone());
			auto action3 = TargetedAction::create(sheep3, action->clone());

			this->runAction(Spawn::create(action1, action2, action3, nullptr));
			break;
		}
			

		default:
			break;
		}
	});
	this->addChild(btn);

	
	////---------------------------------
	//// Sheep run
	////---------------------------------
	// addAction();

	////---------------------------------
	//// Button
	////---------------------------------
	createButton();
	scheduleUpdate();

	return true;
}
void SceneNewGame::createButton() 
{
	auto _button1 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto _button2 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto _button3 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto _button4 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto _button5 = ui::Button::create("go0.png", "go1.png", "go0.png");

	_button1->setPosition(mLane1 + Vec2(50, 0));
	_button2->setPosition(mLane2 + Vec2(50, 0));
	_button3->setPosition(mLane3 + Vec2(50, 0));
	_button4->setPosition(mLane4 + Vec2(50, 0));
	_button5->setPosition(mLane5 + Vec2(50, 0));

	_button1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			addAction(1);
			break;

		default:
			break;
		}
	});
	_button2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			addAction(2);
			break;

		default:
			break;
		}
	});
	_button3->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
		{
			addAction(2);
			break;
		}

		default:
			break;
		}
	});
	_button4->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			addAction(4);
			break;

		default:
			break;
		}
	});
	_button5->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			addAction(5);
			break;

		default:
			break;
		}
	});

	this->addChild(_button1, 0);
	this->addChild(_button2, 0);
	this->addChild(_button3, 0);
	this->addChild(_button4, 0);
	this->addChild(_button5, 0);
}
cocos2d::Vec2 SceneNewGame::selectLane(int i)
{
	int choice = i;
	switch (choice)
	{
	case 1:
		return mLane1;
		break;
	case 2:
		return mLane2;
		break;
	case 3:
		return mLane3;
		break;
	case 4:
		return mLane4;
		break;
	case 5:
		return mLane5;
		break;
	default:
		break;
	}
}
Vector<Sprite*> location;
void SceneNewGame::addAction(int i) 
{
	auto _sheep = Sprite::create("sheep.png");
	auto moveBy = MoveBy::create(12, Vec2(600, 0));
	_sheep->setPosition(selectLane(i));
	location.pushBack(_sheep);
	this->addChild(_sheep, 0);
	_sheep->runAction(moveBy);

}

void SceneNewGame::update(float detail)
{
}

