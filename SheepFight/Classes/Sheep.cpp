#include <Sheep.h>
#include <Defines.h>

USING_NS_CC;

Sheep::Sheep(cocos2d::Scene* scene, int weight, int direction)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->scene = scene;
	this->type = -1;
	this->alive = true;
	this->setWeight(weight);
	// animation
	Vector<SpriteFrame*> frames;
	if (direction == SHEEP_DIRECTION)
	{
		if (weight == SMALL_SIZE)
		{
			frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP_ANI, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
		}
		else if (weight == MEDIUM_SIZE)
		{
			frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP_ANI, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
		}
		else
		{
			frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP_ANI, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
		}
	}
	else
	{
		if (weight == SMALL_SIZE)
		{
			frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY_ANI, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
		}
		else if (weight == MEDIUM_SIZE)
		{
			frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY_ANI, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
		}
		else
		{
			frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
			frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY_ANI, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
		}
	}
	
	
	auto animation = Animation::createWithSpriteFrames(frames, 0.3f);
	auto animate = Animate::create(animation);

	this->mSprite = Sprite::create();
	this->mSprite->runAction(RepeatForever::create(animate));
	scene->addChild(mSprite);
}
Sheep::~Sheep()
{
	this->getSprite()->removeFromParent();
}

void Sheep::setId(int id)
{
	this->id = id;
}

int Sheep::getId() 
{
	return this->id;
}

void Sheep::setWeight(int weight)
{
	this->weight = weight;

	switch (this->weight)
	{
	case BIG_SIZE:
		this->type = BIG_SHEEP_TYPE;
		break;
	case MEDIUM_SIZE:
		this->type = MEDIUM_SHEEP_TYPE;
		break;
	case SMALL_SIZE:
		this->type = SMALL_SIZE;
		break;
	}
}

int Sheep::getWeight()
{
	return this->weight;
}

void Sheep::setVelocity(cocos2d::Vec2 velocity)
{
	this->velocity = velocity;
}

cocos2d::Vec2 Sheep::getVelocity()
{
	return this->velocity;
}

void Sheep::setLane(int lane)
{
	this->lane = lane;
}

int Sheep::getLane()
{
	return this->lane;
}

void Sheep::setHead(Sheep *head) 
{
	this->head = head;
}

Sheep * Sheep::getHead() 
{
	return this->head;
}

void Sheep::setTail(Sheep *tail)
{
	this->tail = tail;
}

Sheep * Sheep::getTail()
{
	return this->tail;
}

void Sheep::moveBack()
{
	this->setPosition(Vec2(this->getPosition().x - this->direction * this->getVelocity().x,
					  this->getPosition().y - this->direction * this->getVelocity().y));
}

bool Sheep::simulateColisionSheepMoveBack(Sheep* otherSheep)
{
	this->moveBack();

	bool result = false;
	
	if (this->getSprite()->getBoundingBox().intersectsRect(otherSheep->getSprite()->getBoundingBox()))
	{
		result = true;
	}

	this->moveForward();

	return result;
}

void Sheep::moveForward()
{
	this->setPosition(Vec2(this->getPosition().x + this->direction * this->getVelocity().x,
					  this->getPosition().y + this->direction * this->getVelocity().y));
}

bool Sheep::simulateColisionSheepMoveForward(Sheep* otherSheep)
{
	this->moveForward();
	bool result = false; 
	Rect a = this->getSprite()->getBoundingBox();
	Rect b = otherSheep->getSprite()->getBoundingBox();
	if (a.intersectsRect(b))
	{
		result = true;
	}
	this->moveBack();

	return result;
}

void Sheep::setDirection(int direction)
{
	this->direction = direction;
}

int Sheep::getDirection()
{
	return this->direction;
}

void Sheep::setType(int type)
{
	this->type = type;
}

int Sheep::getType()
{
	return this->type;
}

int Sheep::getHeight()
{
	int height = -1;

	switch (this->type)
	{
	case BIG_SHEEP_TYPE:
		height = BIG_SIZE_HEIGHT;
		break;
	case MEDIUM_SHEEP_TYPE:
		height = MEDIUM_SIZE_HEIGHT;
		break;
	case SMALL_SHEEP_TYPE:
		height = SMALL_SIZE_HEIGHT;
		break;
	}

	return height;
}

int Sheep::getWidth()
{
	int width = -1;

	switch (this->type)
	{
	case BIG_SHEEP_TYPE:
		width = BIG_SIZE_WIDTH;
		break;
	case MEDIUM_SHEEP_TYPE:
		width = MEDIUM_SIZE_WIDTH;
		break;
	case SMALL_SHEEP_TYPE:
		width = SMALL_SIZE_WIDTH;
		break;
	}

	return width;
}

void Sheep::Init()
{
}

bool Sheep::isAlive()
{
	return this->alive;
}

void Sheep::setAlive(bool alive)
{
	this->alive = alive;
}

void Sheep::Update()
{
	int width;
	switch (this->type)
	{
	case BIG_SHEEP_TYPE:
		width = BIG_SIZE_WIDTH;
		break;
	case MEDIUM_SHEEP_TYPE:
		width = MEDIUM_SIZE_WIDTH;
		break;
	case SMALL_SHEEP_TYPE:
		width = SMALL_SIZE_WIDTH;
		break;
	}

	if (this->getPosition().x + width < M_START)
	{
		this->alive = false;
		
		if (this->direction == ENEMY_DIRECTION)
		{
			SceneNewGame::scoreEnemy += this->weight;
		}
	}

	
	if (this->getPosition().x > M_END)
	{
		this->alive = false;

		if (this->direction == SHEEP_DIRECTION)
		{
			SceneNewGame::scoreSheep += this->weight;
		}
	}
}

