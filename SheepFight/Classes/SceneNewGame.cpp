#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"
#include "ui/CocosGUI.h"
#include "Sheep.h"
#include "Space.h"
#include <vector>
#include "proj.win32\Queue.h"

Sheep *space1;

USING_NS_CC;

std::vector<Sheep*> sheeps;
std::vector<Sheep*> enemies;
Queue *queueSheep;
Queue *queueEnemy;

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

	queueSheep = new Queue();
	queueEnemy = new Queue();

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

	createButton();
	scheduleUpdate();

	return true;
}

void SceneNewGame::createButton() 
{
	auto _button1 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto _button2 = ui::Button::create("go0.png", "go1.png", "go0.png");

	_button1->setPosition(mLane1 + Vec2(50, 0));
	_button2->setPosition(mLane1 + Vec2(600, 0));
	
	_button1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			addActionLeftSheep(1);
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
			addActionRightSheep(1);
			break;

		default:
			break;
		}
	});

	this->addChild(_button1, 0);
	this->addChild(_button2, 0);
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

void SceneNewGame::addActionLeftSheep(int i) 
{
	Sheep *sheep = new Sheep(this);
	sheep->setPosition(cocos2d::Vec2(0, 150));
	sheep->setVelocity(cocos2d::Vec2(2, 0));
	sheep->setAlive(true);
	sheep->setWeight(3);
	sheep->setDirection(SHEEP_DIRECTION);
	sheeps.push_back(sheep);
	queueSheep->push(sheep);
}

void SceneNewGame::addActionRightSheep(int i)
{
	Sheep *enemy = new Sheep(this);
	enemy->setPosition(cocos2d::Vec2(600, 150));
	enemy->setVelocity(cocos2d::Vec2(2, 0));
	enemy->setAlive(true);
	enemy->setWeight(3);
	enemy->setDirection(ENEMY_DIRECTION);
	enemies.push_back(enemy);
	queueEnemy->push(enemy);
}

void SceneNewGame::update(float detail)
{
	// kiểm tra 2 con cừu đầu của sheep và enemy có chạm nhau ko
	bool haveColision = false;

	if (!queueEnemy->empty()
		&& !queueSheep->empty()
		&& queueEnemy->peek()->getSprite()->getBoundingBox().intersectsRect(
			queueSheep->peek()->getSprite()->getBoundingBox()))
	{
		haveColision = true;
	}

	// weight của các con cừu đầu đàn nối đuôi nhau
	int weightOfSheeps = 0;
	// weight của các con cừu (đối phương) đầu đàn nối đuôi nhau
	int weightOfEnemies = 0;

	// lấy cái weight của các con cừu đối nhau
	if (haveColision)
	{
		for (int index = 0; index < queueSheep->getSize(); index++)
		{
			weightOfSheeps += ((Sheep*)queueSheep->get(index))->getWeight();
			if (((Sheep*)queueSheep->get(index))->getTail() == nullptr)
				break;
		}

		for (int index = 0; index < queueEnemy->getSize(); index++)
		{
			weightOfEnemies += ((Sheep*)queueEnemy->get(index))->getWeight();
			if (((Sheep*)queueEnemy->get(index))->getTail() == nullptr)
				break;
		}
	}

	Sheep* currentSheep;
	Sheep* previousSheep;

	// chia trường hợp va chạm
	if (haveColision)
	{
		if (weightOfSheeps == weightOfEnemies)
		{
			move(queueSheep);
			move(queueEnemy);
		}
		else if (weightOfSheeps > weightOfEnemies)
		{
			moveWhenNoBalance(queueSheep, queueEnemy);
		}
		else if (weightOfEnemies > weightOfSheeps)
		{
			moveWhenNoBalance(queueEnemy, queueSheep);
		}
	}
	else
	{
		for (int index = 0; index < queueSheep->getSize(); index++)
		{
			((Sheep*)queueSheep->get(index))->moveForward();
		}

		for (int index = 0; index < queueEnemy->getSize(); index++)
		{
			((Sheep*)queueEnemy->get(index))->moveForward();
		}
	}
}

void SceneNewGame::updateForEachLane(int lane)
{

	
}

void SceneNewGame::move(Queue *queue)
{
	Sheep* currentSheep;
	Sheep* previousSheep;

	for (int index = queue->getSize() - 1; index > 0; index--)
	{
		if (((Sheep*)queue->get(index))->getHead() == nullptr)
		{
			currentSheep = (Sheep*)queue->get(index);
			previousSheep = (Sheep*)queue->get(index - 1);

			if (currentSheep->simulateColisionSheepMoveForward(previousSheep))
			{
				currentSheep->setHead(previousSheep);
				previousSheep->setTail(currentSheep);
				currentSheep->setPosition(Vec2(previousSheep->getPosition().x - previousSheep->getDirection() * WIDTH_SHEEP, currentSheep->getPosition().y));
				break;
			}
			else
			{
				currentSheep->moveForward();
			}
		}
		else
		{
			break;
		}
	}
}

void SceneNewGame::moveWhenNoBalance(Queue *queueWin, Queue *queueLost)
{
	int indexTemp = -1;
	for (int index = 0; index < queueLost->getSize(); index++)
	{
		if (((Sheep*)queueLost->get(index))->getTail() == nullptr)
		{
			indexTemp = index;
			break;
		}
	}

	Sheep * currentSheep;
	Sheep * nextSheep;
	Sheep * previousSheep;

	for (int index = indexTemp; index >= 0; index--)
	{
		currentSheep = (Sheep*)queueLost->get(index);

		if (index == indexTemp && queueLost->isExist(index + 1))
		{
			nextSheep = (Sheep*)queueLost->get(index + 1);
			if (currentSheep->simulateColisionSheepMoveBack(nextSheep))
			{
				currentSheep->setTail(nextSheep);
				nextSheep->setHead(currentSheep);
				currentSheep->setPosition(Vec2(nextSheep->getPosition().x + currentSheep->getDirection() * WIDTH_SHEEP, currentSheep->getPosition().y));
			}
			else
			{
				currentSheep->moveBack();
			}
		} 
		else
		{
			currentSheep->moveBack();
		}
	}
	
	for (int index = indexTemp + 1; index < queueLost->getSize(); index++)
	{
		currentSheep = (Sheep*)queueLost->get(index);
		
		if (queueLost->isExist(index - 1))
		{
			previousSheep = (Sheep*)queueLost->get(index - 1);
			if (currentSheep->simulateColisionSheepMoveForward(previousSheep))
			{
				currentSheep->setHead(previousSheep);
				previousSheep->setTail(currentSheep);
				currentSheep->setPosition(Vec2(previousSheep->getPosition().x - currentSheep->getDirection() * WIDTH_SHEEP, currentSheep->getPosition().y));
			}
			else
			{
				currentSheep->moveForward();
			}
		}
		else
		{
			currentSheep->moveForward();
		}
	}

	for (int index = 0; index < queueWin->getSize(); index++)
	{
		currentSheep = (Sheep*)queueWin->get(index);

		if (index == 0)
		{
			nextSheep = (Sheep*)queueLost->get(0);
		}
		else
		{
			nextSheep = (Sheep*)queueWin->get(index - 1);
		}

		if (currentSheep->simulateColisionSheepMoveForward(nextSheep))
		{
			if (currentSheep->getHead() == nullptr && index != 0)
				currentSheep->setHead(nextSheep);
			currentSheep->setPosition(Vec2(nextSheep->getPosition().x - currentSheep->getDirection() * WIDTH_SHEEP, currentSheep->getPosition().y));
		}
		else
		{
			currentSheep->moveForward();
		}
	}
}