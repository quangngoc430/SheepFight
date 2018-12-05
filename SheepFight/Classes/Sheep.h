#pragma once
#include <Model.h>

class Sheep : public Model
{
private:
	int id;
	int weight;
	cocos2d::Vec2 velocity;
	int lane;
	Sheep *head;
	Sheep *tail;
	int direction;
	cocos2d::Scene* scene;

public:
	Sheep(cocos2d::Scene* scene);
	~Sheep();

	void setId(int id);
	int getId();
	void setWeight(int weight);
	int getWeight();
	void setVelocity(cocos2d::Vec2 velocity);
	cocos2d::Vec2 getVelocity();
	void setLane(int lane);
	int getLane();
	void setHead(Sheep *head);
	Sheep * getHead();
	void setTail(Sheep *tail);
	Sheep * getTail();
	void moveBack();
	bool simulateColisionSheepMoveBack(Sheep*);
	void moveForward();
	bool simulateColisionSheepMoveForward(Sheep*);
	void setDirection(int direction);
	int getDirection();
	Sheep * clone();

	void Init();
	void Update();
};