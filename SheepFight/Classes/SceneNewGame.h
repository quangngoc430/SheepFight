#pragma once
#include "cocos2d.h"
#include "Queue.h"

class SceneNewGame : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(SceneNewGame);
	cocos2d::Vec2 selectLane(int lane, int direction);
	void addActionSheep(int lane, int weight, int direction);
	void createButton();
	void moveWhenBalance(Queue *queue);
	void moveWhenNoBalance(Queue *queueWin, Queue *queueLost);
	bool checkCanCreateSheep(int lane, int direction);
	void setTypeSheep(int typeSheep[]);
	void textOnScreen();
	void createPredictSheep(int wSheep, int wEnemy);

	virtual void update(float detail);
	void updateForEachLane(int lane);
}; 
