#pragma once

#include <cocos2d.h>

class Model
{
protected:
	cocos2d::Sprite* mSprite;
	bool mIsAlive;
	
public:
	Model();
	~Model();

	void setSprite(cocos2d::Sprite* mSprite);
	cocos2d::Sprite* getSprite();
	void setPosition(cocos2d::Vec2 pos);
	cocos2d::Vec2 getPosition();

	void setAlive(bool isAlive);
	bool isAlive();
	

};