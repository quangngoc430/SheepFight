#include <Sheep.h>
#include <Defines.h>

USING_NS_CC;

Sheep::Sheep(cocos2d::Scene* scene, int type, int direction, bool runAni)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->scene = scene;
	this->type = type;
	this->direction = direction;

	if (!runAni)
	{ 
		if (direction == SHEEP_DIRECTION)
		{
			switch (type)
			{
			case SMALL_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_SMALL_SHEEP_2);
				break;
			case MEDIUM_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_MEDIUM_SHEEP_2);
				break;
			case BIG_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_BIG_SHEEP_2);
				break;				
			}
		}
		else
		{
			switch (type)
			{
			case SMALL_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_SMALL_ENEMY_2);
				break;
			case MEDIUM_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_MEDIUM_ENEMY_2);
				break;
			case BIG_SHEEP_TYPE:
				this->mSprite = Sprite::create(IMG_BIG_ENEMY_2);
				break;
			}
		}
	}
	else
	{
		Vector<SpriteFrame*> frames;
		if (direction == SHEEP_DIRECTION)
		{
			switch (this->type)
			{
			case SMALL_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP_1, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP_2, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP_3, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_SHEEP_4, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				break;
			case MEDIUM_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP_1, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP_2, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP_3, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_SHEEP_4, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				break;
			case BIG_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP_1, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP_2, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP_3, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_SHEEP_4, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				break;
			}
		}
		else
		{
			switch (this->type)
			{
			case SMALL_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY_1, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY_2, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY_3, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_SMALL_ENEMY_4, Rect(0, 0, SMALL_SIZE_WIDTH, SMALL_SIZE_HEIGHT)));
				break;
			case MEDIUM_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY_1, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY_2, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY_3, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_MEDIUM_ENEMY_4, Rect(0, 0, MEDIUM_SIZE_WIDTH, MEDIUM_SIZE_HEIGHT)));
				break;
			case BIG_SHEEP_TYPE:
				frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY_1, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY_2, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY_3, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				frames.pushBack(SpriteFrame::create(IMG_BIG_ENEMY_4, Rect(0, 0, BIG_SIZE_WIDTH, BIG_SIZE_HEIGHT)));
				break;
			}

			
		}
		auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
		auto animate = Animate::create(animation);
		this->mSprite = Sprite::create();
		this->mSprite->runAction(RepeatForever::create(animate));
	}

	this->setAlive(true);
	this->setType(type);

	this->scene->addChild(mSprite);
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
									this->getPosition().y));
}

bool Sheep::simulateColisionSheepMoveBack(Sheep* otherSheep)
{
	this->moveBack();

	bool result = false;
	
	//if (this->getSprite()->getBoundingBox().intersectsRect(otherSheep->getSprite()->getBoundingBox()))
	if (this->isCollision(otherSheep))
	{
		result = true;
	}

	this->moveForward();

	return result;
}

void Sheep::moveForward()
{
	this->setPosition(Vec2(this->getPosition().x + this->direction * this->getVelocity().x,
						   this->getPosition().y));
}

bool Sheep::simulateColisionSheepMoveForward(Sheep* otherSheep)
{
	this->moveForward();
	bool result = false; 
	Rect a = this->mSprite->getBoundingBox();
	Rect b = otherSheep->getSprite()->getBoundingBox();
	
	//if (a.intersectsRect(b))
	if (this->isCollision(otherSheep))
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
	
	switch (this->type)
	{
		case BIG_SHEEP_TYPE:
		{
			this->width = BIG_SIZE_WIDTH;
			this->height = BIG_SIZE_HEIGHT;
			this->weight = BIG_SIZE;
			break;
		}
		
		case MEDIUM_SHEEP_TYPE:
		{
			this->width = MEDIUM_SIZE_WIDTH;
			this->height = MEDIUM_SIZE_HEIGHT;
			this->weight = MEDIUM_SIZE;
			break;
		}
		case SMALL_SHEEP_TYPE:
		{
			this->width = SMALL_SIZE_WIDTH;
			this->height = SMALL_SIZE_HEIGHT;
			this->weight = SMALL_SIZE;
			break;
		}
	}
}

int Sheep::getType()
{
	return this->type;
}

void Sheep::setWidth(int width)
{
	this->width = width;
}

int Sheep::getWidth()
{
	return this->width;
}

void Sheep::setHeight(int height)
{
	switch (this->type)
	{
	case BIG_SHEEP_TYPE:
		this->height = BIG_SIZE_HEIGHT;
		break;
	case MEDIUM_SHEEP_TYPE:
		this->height = MEDIUM_SIZE_HEIGHT;
		break;
	case SMALL_SHEEP_TYPE:
		this->height = SMALL_SIZE_HEIGHT;
		break;
	}
}

int Sheep::getHeight()
{
	return this->height;
}

bool Sheep::isCollision(Sheep * otherSheep)
{
	return (((this->getPosition().x <= otherSheep->getPosition().x) &&
			(otherSheep->getPosition().x <= (this->getPosition().x + this->getWidth()))) || 
			((otherSheep->getPosition().x <= this->getPosition().x) && 
			(this->getPosition().x <= (otherSheep->getPosition().x + otherSheep->getWidth()))));
}

void Sheep::Init()
{
}

void Sheep::Update()
{

	if (this->getPosition().x + this->width < M_START)
	{
		this->setAlive(false);
		
		if (this->direction == ENEMY_DIRECTION)
		{
			SceneNewGame::scoreEnemy += this->weight;
		}
	}

	
	if (this->getPosition().x > M_END)
	{
		this->setAlive(false);

		if (this->direction == SHEEP_DIRECTION)
		{
			SceneNewGame::scoreSheep += this->weight;
		}
	}
}

void Sheep::replaceSprite(int type, int direction)
{
	if (direction == SHEEP_DIRECTION)
	{
		switch (type)
		{
			case SMALL_SHEEP_TYPE:
				mSprite->setTexture(IMG_SMALL_SHEEP_2);
				break;
			case MEDIUM_SHEEP_TYPE:
				mSprite->setTexture(IMG_MEDIUM_SHEEP_2);
				break;
			case BIG_SHEEP_TYPE:
				mSprite->setTexture(IMG_BIG_SHEEP_2);
				break;
		}
	
	}
	else
	{
		switch (type)
		{
		case SMALL_SHEEP_TYPE:
			mSprite->setTexture(IMG_SMALL_ENEMY_2);
			break;
		case MEDIUM_SHEEP_TYPE:
			mSprite->setTexture(IMG_MEDIUM_ENEMY_2);
			break;
		case BIG_SHEEP_TYPE:
			mSprite->setTexture(IMG_BIG_ENEMY_2);
			break;
		}
	}
}