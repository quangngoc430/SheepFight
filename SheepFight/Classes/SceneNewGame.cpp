#include "SceneNewGame.h"
#include "Defines.h"
#include "SceneMenu.h"
#include "Sheep.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"
#include <vector>


USING_NS_CC;

std::vector<Queue*> vectorQueueSheep;
std::vector<Queue*> vectorQueueEnemy;
int countElement;
int countDelayEnemy;
int countDelaySheep;
int typeSheep[2] = {0, 0};
int typeEnemy[2] = {0, 0};
Sheep *space1;
int SceneNewGame::scoreSheep = DEFAULT_SCORE;
int SceneNewGame::scoreEnemy = DEFAULT_SCORE;
Label* scoreSheepLabel;
Label* scoreEnemyLabel;
Label *label;
Label *gameOver;
Sheep *predictSheep;
Sheep *predictEnemy;
Sprite * btnBlockSheep;

Sprite * btnPauseGame;

bool isLockBtn = true;
bool isPausedGame = false;

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

	// audio
	auto audio = CocosDenshion::SimpleAudioEngine::getInstance();

	// Thiết lập play background music và được lặp đi lặp lại liên tục.
	audio->playBackgroundMusic("handclap.mp3", true);

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

	//// Create predict sheep
	setTypeSheep(typeSheep);
	setTypeSheep(typeEnemy);
	createPredictSheep(typeSheep[0], typeEnemy[0]);
	gameOver = Label::createWithTTF("0", "fonts/Marker-Felt.ttf", 100);
	gameOver->setColor(Color3B::RED);
	gameOver->setAlignment(cocos2d::TextHAlignment::CENTER);
	gameOver->setPosition(GAME_OVER);
	gameOver->setVisible(false);
	addChild(gameOver);
	return true;
}

void SceneNewGame::setTypeSheep(int typeSheep[])
{
	if (typeSheep[0] == 0)
	{
		typeSheep[1] = round(random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE));
		typeSheep[0] = round(random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE));
	}
	else
	{
		typeSheep[0] = typeSheep[1];
		typeSheep[1] = round(random(SMALL_SHEEP_TYPE, BIG_SHEEP_TYPE));
	}
}

void SceneNewGame::textOnScreen()
{
	scoreSheepLabel = Label::createWithTTF("0", "fonts/Marker-Felt.ttf", 30);
	scoreSheepLabel->setColor(Color3B::RED);
	scoreSheepLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
	scoreSheepLabel->setPosition(SCORE_SHEEP);
	addChild(scoreSheepLabel);

	scoreEnemyLabel = Label::createWithTTF("0", "fonts/Marker-Felt.ttf", 30);
	scoreEnemyLabel->setColor(Color3B::WHITE);
	scoreEnemyLabel->setAlignment(cocos2d::TextHAlignment::CENTER);
	scoreEnemyLabel->setPosition(SCORE_ENEMY);
	addChild(scoreEnemyLabel);

	delaySheep = Label::createWithTTF("0", "fonts/Marker Felt.ttf ", 20);
	delaySheep->setColor(Color3B::GREEN);
	delaySheep->setAlignment(cocos2d::TextHAlignment::CENTER);
	delaySheep->setPosition(DELAY_SHEEP);
	addChild(delaySheep);

	delayEnemy = Label::createWithTTF("0", "fonts/Marker Felt.ttf ", 20);
	delayEnemy->setColor(Color3B::GREEN);
	delayEnemy->setAlignment(cocos2d::TextHAlignment::CENTER);
	delayEnemy->setPosition(DELAY_ENEMY);
	addChild(delayEnemy);

	gameOver = Label::createWithTTF("0", "fonts/Marker Felt.ttf ", 100);
	gameOver->setColor(Color3B::RED);
	gameOver->setAlignment(cocos2d::TextHAlignment::CENTER);
	gameOver->setPosition(GAME_OVER);
	gameOver->setVisible(false);
	addChild(gameOver);

}

void SceneNewGame::createPredictSheep(int wSheep, int wEnemy)
{
	predictSheep = new Sheep(this, wSheep, SHEEP_DIRECTION, false);
	predictSheep->setPosition(PREDICT_SHEEP);
	predictSheep->setAlive(true);
	predictSheep->setWeight(wSheep);
	predictSheep->setDirection(SHEEP_DIRECTION);
	
	predictEnemy = new Sheep(this, wEnemy, ENEMY_DIRECTION, false);
	predictEnemy->setPosition(PREDICT_ENEMY);
	predictEnemy->setAlive(true);
	predictEnemy->setWeight(wEnemy);
	predictEnemy->setDirection(ENEMY_DIRECTION);
}

void SceneNewGame::createButton() 
{
	auto buttonCreatePauseGame = ui::Button::create("Pause.png", "Pause.png", "Pause.png");
	auto buttonCreateSheepLane0 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane1 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane2 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane3 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	auto buttonCreateSheepLane4 = ui::Button::create(IMG_GO, "GoSelected.png", "GoSelected.png");
	btnBlockSheep = Sprite::create(IMG_BLOCK);
	btnPauseGame = Sprite::create("Pause.png");

	buttonCreatePauseGame->setPosition(Vec2(400, 438));
	btnPauseGame->setPosition(Vec2(400, 438));
	buttonCreateSheepLane0->setPosition(BTN_SHEEP_LANE_0);
	buttonCreateSheepLane1->setPosition(BTN_SHEEP_LANE_1);
	buttonCreateSheepLane2->setPosition(BTN_SHEEP_LANE_2);
	buttonCreateSheepLane3->setPosition(BTN_SHEEP_LANE_3);
	buttonCreateSheepLane4->setPosition(BTN_SHEEP_LANE_4);
	btnBlockSheep->setPosition(BTN_BLOCK_SHEEP);


	buttonCreatePauseGame->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			isPausedGame = !isPausedGame;
			if (isPausedGame)
				btnPauseGame->setTexture("Play.png");
			else
				btnPauseGame->setTexture("Pause.png");
			break;

		default:
			break;
		}
	});

	buttonCreateSheepLane0->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			if (checkCanCreateSheep(LANE_0, SHEEP_DIRECTION) && !isPausedGame && !isLockBtn)
			{
				setTypeSheep(typeSheep);
				predictSheep->replaceSprite(typeSheep[1], SHEEP_DIRECTION);
				addActionSheep(LANE_0, typeSheep[0], SHEEP_DIRECTION);
				isLockBtn = true;
				btnBlockSheep->setVisible(true);
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
			if (checkCanCreateSheep(LANE_1, SHEEP_DIRECTION) && !isPausedGame && !isLockBtn)
			{
				setTypeSheep(typeSheep);
				predictSheep->replaceSprite(typeSheep[1], SHEEP_DIRECTION);
				addActionSheep(LANE_1, typeSheep[0], SHEEP_DIRECTION);
				isLockBtn = true;
				btnBlockSheep->setVisible(true);
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
			if (checkCanCreateSheep(LANE_2, SHEEP_DIRECTION) && !isPausedGame && !isLockBtn)
			{
				setTypeSheep(typeSheep);
				predictSheep->replaceSprite(typeSheep[1], SHEEP_DIRECTION);
				addActionSheep(LANE_2, typeSheep[0], SHEEP_DIRECTION);
				isLockBtn = true;
				btnBlockSheep->setVisible(true);
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
			if (checkCanCreateSheep(LANE_3, SHEEP_DIRECTION) && !isPausedGame && !isLockBtn)
			{
				setTypeSheep(typeSheep);
				predictSheep->replaceSprite(typeSheep[1], SHEEP_DIRECTION);
				addActionSheep(LANE_3, typeSheep[0], SHEEP_DIRECTION);
				isLockBtn = true;
				btnBlockSheep->setVisible(true);
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
			if (checkCanCreateSheep(LANE_4, SHEEP_DIRECTION) && !isPausedGame && !isLockBtn)
			{
				setTypeSheep(typeSheep);
				predictSheep->replaceSprite(typeSheep[1], SHEEP_DIRECTION);
				addActionSheep(LANE_4, typeSheep[0], SHEEP_DIRECTION);
				isLockBtn = true;
				btnBlockSheep->setVisible(true);
			}
			break;

		default:
			break;
		}
	});

	this->addChild(btnBlockSheep, 1);
	this->addChild(btnPauseGame, 1);
	this->addChild(buttonCreatePauseGame, 0);
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
	Sheep *sheep = new Sheep(this, type, direction, true);
	sheep->setId(countElement++);
	sheep->setPosition(selectLane(lane, direction));
	sheep->setVelocity(cocos2d::Vec2(2, 0));
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
	if (countDelaySheep == 120)
	{
		isLockBtn = false;
		countDelaySheep = 0;		
		delaySheep->setString("GO GO");
	}
	if (isLockBtn == true)
	{
		delaySheep->setString(std::to_string(countDelaySheep));
		countDelaySheep++;
	}
	
	if (!isPausedGame)
	{
		if (countDelaySheep == 120)
		{
			isLockBtn = false;
			countDelaySheep = 0;
			btnBlockSheep->setVisible(false);
		}
		if (isLockBtn == true)
		{
			countDelaySheep++;
		}

		// random enemy
		countDelayEnemy++;
		if (countDelayEnemy % 130 == 0)
		{
			setTypeSheep(typeEnemy);
			predictEnemy->replaceSprite(typeEnemy[1], ENEMY_DIRECTION);
			addActionSheep(random(LANE_0, LANE_4), typeEnemy[0], ENEMY_DIRECTION);
			countDelayEnemy = 0;
		}

		for (int lane = 0; lane < MAX_LANES; lane++)
		{
			updateForEachLane(lane);
		}

		updateScoreOnScreen();
	}	

	if (scoreSheep > 10)
	{
		gameOver->setVisible(true);
		gameOver->setString("VICTORY");
		Director::getInstance()->replaceScene(GameOverScene::create());
	}
	if (scoreEnemy >= 10)
	{
		gameOver->setVisible(true);
		gameOver->setString("DEFEAT");
		Director::getInstance()->replaceScene(GameOverScene::create());
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

		if (SceneNewGame::scoreSheep >= MAX_SCORE) {
			// hiện thắng
			gameOver->setVisible(true);
			gameOver->setString("VICTORY");
			Director::getInstance()->replaceScene(GameOverScene::create());
		}

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
		
		if (SceneNewGame::scoreEnemy >= MAX_SCORE) {
			gameOver->setVisible(true);
			gameOver->setString("DEFEAT");
			Director::getInstance()->replaceScene(GameOverScene::create());
		}

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
		for (int index = 0; index < vectorQueueSheep.at(lane)->getSize(); index++)
		{
			sheep = (Sheep*)(vectorQueueSheep.at(lane))->get(index);
				
			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep 
			if (sheep->getPosition().x < M_START + sheep->getWidth())
				return false;
		}
			
		for (int index = 0; index < vectorQueueEnemy.at(lane)->getSize(); index++)
		{
			sheep = (Sheep*)(vectorQueueEnemy.at(lane))->get(index);

			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep 
			if (sheep->getPosition().x < M_START + sheep->getWidth())
				return false;
		}
	}
	else if (direction == ENEMY_DIRECTION)
	{
		for (int index = 0; index < vectorQueueSheep.at(lane)->getSize(); index++)
		{
			sheep = (Sheep*)(vectorQueueSheep.at(lane))->get(index);

			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep 
			if (sheep->getPosition().x + sheep->getWidth() > 750 - sheep->getWidth())
				return false;
		}

		for (int index = 0; index < vectorQueueEnemy.at(lane)->getSize(); index++)
		{
			sheep = (Sheep*)(vectorQueueEnemy.at(lane))->get(index);

			// replace true value (sheep->getWidth) in the next release after finish function generate random sheep 
			if (sheep->getPosition().x + sheep->getWidth() > 750 - sheep->getWidth())
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