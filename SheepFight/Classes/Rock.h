#pragma once
#include <Model.h>

class Rock : public Model
{
private:
	int mMoveStep;

public:
	Rock(cocos2d::Scene* scene);
	~Rock();

	void Init();
	void Update();
};