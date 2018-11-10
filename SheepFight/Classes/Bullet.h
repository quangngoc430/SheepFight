#pragma once
#include <Model.h>

class Bullet : public Model
{
private:
	int mMoveStep;

public:
	Bullet(cocos2d::Scene* scene);
	~Bullet();

	void Init();
	void Update();
};