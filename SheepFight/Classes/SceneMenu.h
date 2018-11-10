#pragma once
#include "cocos2d.h"

class SceneMenu : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update(float detail);
	CREATE_FUNC(SceneMenu);
}; 
