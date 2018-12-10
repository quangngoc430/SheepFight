#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"
#include "Sheep.h"
#include <vector>


USING_NS_CC;

std::vector<Queue*> vectorQueueSheep;
std::vector<Queue*> vectorQueueEnemy;
int countElement;
int countFPS;
int typeSheep[2] = { 0, 0 };
int typeEnemy[2] = { 0, 0 };
Sheep *space1;
int SceneNewGame::scoreSheep = DEFAULT_SCORE;
int SceneNewGame::scoreEnemy = DEFAULT_SCORE;
Label* scoreSheepLabel;
Label* scoreEnemyLabel;
Label *label;

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
	
	auto sprite = Sprite::create(IMG_PLAY_BACKGROUND);
	
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
	textOnScreen();

	return true;
}

void SceneNewGame::setTypeSheep(int typeSheep[])
{
	if (typeSheep[0] == 0)
	{
		typeSheep[1] = round(random(1, 3));
		typeSheep[0] = round(random(1, 3));
	}
	else
	{
		typeSheep[0] = typeSheep[1];
		typeSheep[1] = round(random(1, 3));
	}
}

void SceneNewGame::textOnScreen()
{
	scoreSheepLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf ", 30);
	scoreSheepLabel->setColor(Color3B::RED);
	scoreSheepLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
	scoreSheepLabel->setPosition(SCORE_SHEEP);
	addChild(scoreSheepLabel);

	scoreEnemyLabel = Label::createWithTTF("0", "fonts/Marker Felt.ttf ", 30);
	scoreEnemyLabel->setColor(Color3B::WHITE);
	scoreEnemyLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
	scoreEnemyLabel->setPosition(SCORE_ENEMY);
	addChild(scoreEnemyLabel);
}

void SceneNewGame::createButton() 
{
	auto buttonCreateSheepLane0 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane1 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane2 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane3 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane4 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");

	buttonCreateSheepLane0->setPosition(BTN_SHEEP_LANE_0);
	buttonCreateSheepLane1->setPosition(BTN_SHEEP_LANE_1);
	buttonCreateSheepLane2->setPosition(BTN_SHEEP_LANE_2);
	buttonCreateSheepLane3->setPosition(BTN_SHEEP_LANE_3);
	buttonCreateSheepLane4->setPosition(BTN_SHEEP_LANE_4);
	
	buttonCreateSheepLane0->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(LANE_0, SHEEP_DIRECTION))
			{
				setTypeSheep(typeSheep);
				addActionSheep(LANE_0, random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE), SHEEP_DIRECTION);
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
			if (checkCanCreateSheep(LANE_1, SHEEP_DIRECTION))
			{
				setTypeSheep(typeSheep);
				addActionSheep(LANE_1, random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE), SHEEP_DIRECTION);
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
			if (checkCanCreateSheep(LANE_2, SHEEP_DIRECTION))
			{
				setTypeSheep(typeSheep);
				addActionSheep(LANE_2, random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE), SHEEP_DIRECTION);
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
			if (checkCanCreateSheep(LANE_3, SHEEP_DIRECTION))
			{
				setTypeSheep(typeSheep);
				addActionSheep(LANE_3, random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE), SHEEP_DIRECTION);
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
			if (checkCanCreateSheep(LANE_4, SHEEP_DIRECTION))
			{
				setTypeSheep(typeSheep);
				addActionSheep(LANE_4, random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE), SHEEP_DIRECTION);
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

void SceneNewGame::addActionSheep(int lane, int type, int direction)
{
	Sheep *sheep = new Sheep(this, type, direction);
	sheep->setId(countElement++);
	sheep->setPosition(selectLane(lane, direction));
	sheep->setVelocity(cocos2d::Vec2(2, 0));
	sheep->setAlive(true);
	if (direction == SHEEP_DIRECTION)
	{
		vectorQueueSheep.at(lane)->push(sheep);
	}
	else
	{
		vectorQueueEnemy.at(lane)->push(sheep);
	}
}

void SceneNewGame::update(float detail)
{
	// random enemy
	countFPS++;
	if (countFPS % 120 == 0)
	{
		addActionSheep(random(LANE_0, LANE_4), random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE) , ENEMY_DIRECTION);
	}
	
	for (int lane = 0; lane < MAX_LANES; lane++)
	{
		updateForEachLane(lane);
	}

	updateScoreOnScreen();
}

void SceneNewGame::updateForEachLane(int lane)
{
	Queue *queueSheep = vectorQueueSheep.at(lane);
	Queue *queueEnemy = vectorQueueEnemy.at(lane);

	// kiểm tra 2 con cừu đầu của sheep và enemy có chạm nhau ko
	bool haveColision = false;

	if (!queueEnemy->empty()
		&& !queueSheep->empty()
		&& ((Sheep*)queueEnemy->peek())
		->isCollision((Sheep*)queueSheep->peek()))
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
		currentSheep = ((Sheep*)queueSheep->get(index));
		currentSheep->Update();

		if (!currentSheep->isAlive()) 
		{
			if (currentSheep->getHead() == nullptr)
			{
				if (currentSheep->getTail() != nullptr)
				{
					currentSheep->getTail()->setHead(nullptr);
				}
			}
			else
			{
				if (currentSheep->getTail() == nullptr)
				{
					currentSheep->getHead()->setTail(nullptr);
				}
				else
				{
					currentSheep->getHead()->setTail(currentSheep->getTail());
				}
			}
			queueSheep->remove(index);
			delete currentSheep;
		}
		
	}

	for (int index = 0; index < queueEnemy->getSize(); index++)
	{
		currentSheep = ((Sheep*)queueEnemy->get(index));
		currentSheep->Update();

		if (!currentSheep->isAlive())
		{
			if (currentSheep->getHead() == nullptr)
			{
				if (currentSheep->getTail() != nullptr)
				{
					currentSheep->getTail()->setHead(nullptr);
				}
			}
			else
			{
				if (currentSheep->getTail() == nullptr)
				{
					currentSheep->getHead()->setTail(nullptr);
				}
				else
				{
					currentSheep->getHead()->setTail(currentSheep->getTail());
				}
			}
			queueEnemy->remove(index);
			delete currentSheep;
		}

		
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
				if (currentSheep->getDirection() == SHEEP_DIRECTION)
				{
					currentSheep->setPosition(Vec2(previousSheep->getPosition().x - currentSheep->getWidth(), previousSheep->getPosition().y));
				}
				else
				{
					currentSheep->setPosition(Vec2(previousSheep->getPosition().x + previousSheep->getWidth(), previousSheep->getPosition().y));
				}
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
				if (currentSheep->getDirection() == SHEEP_DIRECTION)
				{
					currentSheep->setPosition(Vec2(nextSheep->getPosition().x + nextSheep->getWidth(), nextSheep->getPosition().y));
				}
				else
				{
					currentSheep->setPosition(Vec2(nextSheep->getPosition().x - currentSheep->getWidth(), nextSheep->getPosition().y));
				}
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
				if (currentSheep->getDirection() == SHEEP_DIRECTION)
				{
					currentSheep->setPosition(Vec2(previousSheep->getPosition().x - currentSheep->getWidth(), previousSheep->getPosition().y));
				}
				else
				{
					currentSheep->setPosition(Vec2(previousSheep->getPosition().x + previousSheep->getWidth(), previousSheep->getPosition().y));
				}
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
			if (currentSheep->getDirection() == SHEEP_DIRECTION)
			{
				currentSheep->setPosition(Vec2(nextSheep->getPosition().x - currentSheep->getWidth(), nextSheep->getPosition().y));
			}
			else
			{
				currentSheep->setPosition(Vec2(nextSheep->getPosition().x + nextSheep->getWidth(), nextSheep->getPosition().y));
			}
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

void SceneNewGame::updateScoreOnScreen()
{
	scoreEnemyLabel->setString(std::to_string(SceneNewGame::scoreEnemy));
	scoreSheepLabel->setString(std::to_string(SceneNewGame::scoreSheep));
}