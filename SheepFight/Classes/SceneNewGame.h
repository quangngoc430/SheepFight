#pragma once
#include "cocos2d.h"

class SceneNewGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SceneNewGame);
	cocos2d::Vec2 selectLane(int i);
	void addAction(int i);
	void createButton();
}; 
