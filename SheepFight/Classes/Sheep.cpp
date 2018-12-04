#include <Sheep.h>
#include <Defines.h>

USING_NS_CC;

Sheep::Sheep(cocos2d::Scene* scene)
{
	this->mSprite = Sprite::create(IMG_SHEEP);
	scene->addChild(mSprite);
	this->head = nullptr;
	this->tail = nullptr;
	this->scene = scene;
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

Sheep * Sheep::clone()
{
	Sheep *newSheep = new Sheep(this->scene);
	newSheep->setSprite(this->getSprite());
	newSheep->setPosition(this->getPosition());
	newSheep->setVelocity(this->getVelocity());
	newSheep->setLane(this->getLane());
	newSheep->setHead(this->head);
	newSheep->setTail(this->tail);
	newSheep->setDirection(this->direction);
	
	return newSheep;
}