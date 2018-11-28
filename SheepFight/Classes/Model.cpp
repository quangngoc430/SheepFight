#include <Model.h>

USING_NS_CC;

Model::Model() :
	mSprite(nullptr), mIsAlive(false)
{
}
Model::~Model()
{
}

void Model::setSprite(cocos2d::Sprite* mSprite)
{
	this->mSprite = mSprite;
}

cocos2d::Sprite* Model::getSprite()
{
	return this->mSprite;
}

void Model::setPosition(cocos2d::Vec2 pos)
{
	if (this->mSprite != nullptr)
	{
		this->mSprite->setPosition(pos);
	}
}

cocos2d::Vec2 Model::getPosition()
{
	return this->mSprite->getPosition();
}

void Model::setAlive(bool isAlive)
{
	this->mIsAlive = isAlive;
	this->mSprite->setVisible(mIsAlive);
}

bool Model::isAlive()
{
	return this->mIsAlive;
}