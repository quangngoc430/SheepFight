#pragma once
#include "cocos2d.h"
#include "proj.win32\Queue.h"

class SceneNewGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SceneNewGame);
	cocos2d::Vec2 selectLane(int i);
	void addActionLeftSheep(int i);
	void addActionRightSheep(int i);
	void createButton();
	void move(Queue *queue);
	void moveWhenNoBalance(Queue *queueWin, Queue *queueLost);

	virtual void update(float detail);
	void updateForEachLane(int lane);

}; 
