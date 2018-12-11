#include <Sheep.h>
#include <Defines.h>

USING_NS_CC;

Sheep::Sheep(cocos2d::Scene* scene, int weight, int direction, bool runAni)
{
	this->head = nullptr;
	this->tail = nullptr;
	this->scene = scene;
	this->type = -1;

	if (!runAni)
	{
		if (direction == SHEEP_DIRECTION)
		{
			if (weight == SMALL_SIZE)
			{
				this->mSprite = Sprite::create(IMG_SHEEP_TYPE_1);
			}
			else if (weight == MEDIUM_SIZE)
			{
				this->mSprite = Sprite::create(IMG_SHEEP_TYPE_2_ANI);
			}
			else
			{
				this->mSprite = Sprite::create(IMG_SHEEP_TYPE_3_ANI);
			}
		}
		else
		{
			if (weight == SMALL_SIZE)
			{
				this->mSprite = Sprite::create(IMG_ENEMY_TYPE_1_ANI);
			}
			else if (weight == MEDIUM_SIZE)
			{
				this->mSprite = Sprite::create(IMG_ENEMY_TYPE_2_ANI);
			}
			else
			{
				this->mSprite = Sprite::create(IMG_ENEMY_TYPE_3_ANI);
			}
		}
	}
	else
	{
		// animation
		Vector<SpriteFrame*> frames;
		if (direction == SHEEP_DIRECTION)
		{
			if (weight == SMALL_SIZE)
			{
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_1, Rect(0, 0, 70, 56)));
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_1_ANI, Rect(0, 0, 70, 56)));
			}
			else if (weight == MEDIUM_SIZE)
			{
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_2, Rect(0, 0, 70, 56)));
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_2_ANI, Rect(0, 0, 70, 56)));
			}
			else
			{
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_3, Rect(0, 0, 80, 64)));
				frames.pushBack(SpriteFrame::create(IMG_SHEEP_TYPE_3_ANI, Rect(0, 0, 80, 64)));
			}
		}
		else
		{
			if (weight == SMALL_SIZE)
			{
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_1, Rect(0, 0, 70, 56)));
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_1_ANI, Rect(0, 0, 70, 56)));
			}
			else if (weight == MEDIUM_SIZE)
			{
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_2, Rect(0, 0, 70, 56)));
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_2_ANI, Rect(0, 0, 70, 56)));
			}
			else
			{
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_3, Rect(0, 0, 80, 64)));
				frames.pushBack(SpriteFrame::create(IMG_ENEMY_TYPE_3_ANI, Rect(0, 0, 80, 64)));
			}
		}
	
	
		auto animation = Animation::createWithSpriteFrames(frames, 0.1f);
		auto animate = Animate::create(animation);

		this->mSprite = Sprite::create();
		this->mSprite->runAction(RepeatForever::create(animate));
	}
	
	scene->addChild(mSprite);
}


Sheep::~Sheep()
{
	
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

void Sheep::Update()
{
	// code cho enemy và sheep dựa trên cái direction
	// có 2 define là SHEEP_DIRECTION và ENEMY_DIRECTION
	/*if (this->isAlive())
	{
		this->setPosition(this->getPosition() + this->direction * this->getVelocity());
		if (this->getPosition().x > this->mSprite->getContentSize().width + SCREEN_W)
		{
			this->setAlive(false);
		}
	}*/
}

void Sheep::replaceSprite(int weight, int direction)
{
	SpriteFrameCache* spriteFrameCache = SpriteFrameCache::getInstance();
	spriteFrameCache->addSpriteFramesWithFile("SheepNEnemy.plist");
	SpriteFrame * spriteFrame;
	if (direction == SHEEP_DIRECTION)
	{
		switch (weight)
		{
			case SMALL_SIZE:
					spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_SHEEP_TYPE_1);
					break;
			case MEDIUM_SIZE:
					spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_SHEEP_TYPE_2_ANI);
					break;
			case BIG_SIZE:
					spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_SHEEP_TYPE_3_ANI);
					break;
		}
	
	}
	else
	{
		switch (weight)
		{
		case SMALL_SIZE:
			spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_ENEMY_TYPE_1_ANI);
			break;
		case MEDIUM_SIZE:
			spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_ENEMY_TYPE_2_ANI);
			break;
		case BIG_SIZE:
			spriteFrame = spriteFrameCache->getSpriteFrameByName(IMG_ENEMY_TYPE_3_ANI);
			break;
		}
	}

	mSprite->setDisplayFrame(spriteFrame);

}