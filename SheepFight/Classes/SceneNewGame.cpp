#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"
#include "ui/CocosGUI.h"
#include "Sheep.h"
#include "Space.h"
#include <vector>

Sheep *space1;

USING_NS_CC;

std::vector<Queue*> vectorQueueSheep;
std::vector<Queue*> vectorQueueEnemy;
int countElement;


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

	countElement = 0;

	for (int index = 0; index < MAX_LANES; index++)
	{
		vectorQueueSheep.push_back(new Queue());
		vectorQueueEnemy.push_back(new Queue());
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

	createButton();
	scheduleUpdate();

	return true;
}

void SceneNewGame::createButton() 
{
	auto buttonCreateSheepLane0 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateSheepLane1 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateSheepLane2 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateSheepLane3 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateSheepLane4 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateEnemyLane0 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateEnemyLane1 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateEnemyLane2 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateEnemyLane3 = ui::Button::create("go0.png", "go1.png", "go0.png");
	auto buttonCreateEnemyLane4 = ui::Button::create("go0.png", "go1.png", "go0.png");

	buttonCreateSheepLane0->setPosition(BTN_SHEEP_LANE_0);
	buttonCreateSheepLane1->setPosition(BTN_SHEEP_LANE_1);
	buttonCreateSheepLane2->setPosition(BTN_SHEEP_LANE_2);
	buttonCreateSheepLane3->setPosition(BTN_SHEEP_LANE_3);
	buttonCreateSheepLane4->setPosition(BTN_SHEEP_LANE_4);
	buttonCreateEnemyLane0->setPosition(BTN_ENEMY_LANE_0);
	buttonCreateEnemyLane1->setPosition(BTN_ENEMY_LANE_1);
	buttonCreateEnemyLane2->setPosition(BTN_ENEMY_LANE_2);
	buttonCreateEnemyLane3->setPosition(BTN_ENEMY_LANE_3);
	buttonCreateEnemyLane4->setPosition(BTN_ENEMY_LANE_4);
	
	buttonCreateSheepLane0->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(0, SHEEP_DIRECTION))
			{
				addActionSheep(0, BIG_SIZE, SHEEP_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateSheepLane1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(1, SHEEP_DIRECTION))
			{
				addActionSheep(1, BIG_SIZE, SHEEP_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateSheepLane2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(2, SHEEP_DIRECTION))
			{
				addActionSheep(2, BIG_SIZE, SHEEP_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateSheepLane3->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(3, SHEEP_DIRECTION))
			{
				addActionSheep(3, BIG_SIZE, SHEEP_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateSheepLane4->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(4, SHEEP_DIRECTION))
			{
				addActionSheep(4, BIG_SIZE, SHEEP_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateEnemyLane0->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(0, ENEMY_DIRECTION))
			{
				addActionSheep(0, BIG_SIZE, ENEMY_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateEnemyLane1->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(1, ENEMY_DIRECTION))
			{
				addActionSheep(1, BIG_SIZE, ENEMY_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateEnemyLane2->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(2, ENEMY_DIRECTION))
			{
				addActionSheep(2, BIG_SIZE, ENEMY_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateEnemyLane3->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(3, ENEMY_DIRECTION))
			{
				addActionSheep(3, BIG_SIZE, ENEMY_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	buttonCreateEnemyLane4->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(4, ENEMY_DIRECTION))
			{
				addActionSheep(4, BIG_SIZE, ENEMY_DIRECTION);
			}
			break;

		default:
			break;
		}
	});

	this->addChild(buttonCreateSheepLane0, 0);
	this->addChild(buttonCreateSheepLane1, 0);
	this->addChild(buttonCreateSheepLane2, 0);
	this->addChild(buttonCreateSheepLane3, 0);
	this->addChild(buttonCreateSheepLane4, 0);

	this->addChild(buttonCreateEnemyLane0, 0);
	this->addChild(buttonCreateEnemyLane1, 0);
	this->addChild(buttonCreateEnemyLane2, 0);
	this->addChild(buttonCreateEnemyLane3, 0);
	this->addChild(buttonCreateEnemyLane4, 0);
}

cocos2d::Vec2 SceneNewGame::selectLane(int lane, int direction)
{
	switch (lane)
	{
	case LANE_0:
		return (direction == SHEEP_DIRECTION) ? SHEEP_LANE_0 : ENEMY_LANE_0;
		break;
	case LANE_1:
		return (direction == SHEEP_DIRECTION) ? SHEEP_LANE_1 : ENEMY_LANE_1;
		break;
	case LANE_2:
		return (direction == SHEEP_DIRECTION) ? SHEEP_LANE_2 : ENEMY_LANE_2;
		break;
	case LANE_3:
		return (direction == SHEEP_DIRECTION) ? SHEEP_LANE_3 : ENEMY_LANE_3;
		break;
	case LANE_4:
		return (direction == SHEEP_DIRECTION) ? SHEEP_LANE_4 : ENEMY_LANE_4;
		break;
	default:
		break;
	}
}

void SceneNewGame::addActionSheep(int lane, int weight, int direction)
{
	Sheep *sheep = new Sheep(this);
	sheep->setId(countElement);
	countElement++;
	sheep->setPosition(selectLane(lane, direction));
	sheep->setVelocity(cocos2d::Vec2(2, 0));
	sheep->setAlive(true);
	sheep->setWeight(weight);
	sheep->setDirection(direction);
	(direction == SHEEP_DIRECTION) ? vectorQueueSheep.at(lane)->push(sheep) : vectorQueueEnemy.at(lane)->push(sheep);
}

void SceneNewGame::update(float detail)
{
	for (int lane = 0; lane < MAX_LANES; lane++)
	{
		updateForEachLane(lane);
	}
}

void SceneNewGame::updateForEachLane(int lane)
{
	Queue *queueSheep = vectorQueueSheep.at(lane);
	Queue *queueEnemy = vectorQueueEnemy.at(lane);

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
			moveWhenBalance(queueSheep);
			moveWhenBalance(queueEnemy);
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

	for (int index = 0; index < queueSheep->getSize(); index++)
	{
		((Sheep*)queueSheep->get(index))->Update();
	}

	for (int index = 0; index < queueEnemy->getSize(); index++)
	{
		((Sheep*)queueEnemy->get(index))->Update();
	}
}

void SceneNewGame::moveWhenBalance(Queue *queue)
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
				currentSheep->setPosition(Vec2(previousSheep->getPosition().x - previousSheep->getDirection() * previousSheep->getWidth(), currentSheep->getPosition().y));
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
				currentSheep->setPosition(Vec2(nextSheep->getPosition().x + currentSheep->getDirection() * currentSheep->getWidth(), currentSheep->getPosition().y));
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
				currentSheep->setPosition(Vec2(previousSheep->getPosition().x - currentSheep->getDirection() * currentSheep->getWidth(), currentSheep->getPosition().y));
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
			currentSheep->setPosition(Vec2(nextSheep->getPosition().x - currentSheep->getDirection() * currentSheep->getWidth(), currentSheep->getPosition().y));
		}
		else
		{
			currentSheep->moveForward();
		}
	}	
}

bool SceneNewGame::checkCanCreateSheep(int lane, int direction)
{
	Sheep * sheep;

	if (direction == SHEEP_DIRECTION)
	{
		if (vectorQueueSheep.at(lane)->getSize() > 0)
		{
			sheep = (Sheep*)vectorQueueSheep.at(lane)->get(vectorQueueSheep.at(lane)->getSize() - 1);
			
			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep 
			if (sheep->getPosition().x <= sheep->getWidth())
				return false;
		}
	}
	else if (direction == ENEMY_DIRECTION)
	{
		if (vectorQueueEnemy.at(lane)->getSize() > 0)
		{
			sheep = (Sheep*)vectorQueueEnemy.at(lane)->get(vectorQueueEnemy.at(lane)->getSize() - 1);

			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep
			if (sheep->getPosition().x + sheep->getWidth() >= 600)
				return false;
		}
	}

	return true;
}