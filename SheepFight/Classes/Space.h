#pragma once
#include <Model.h>
#include <Sheep.h>

class Space : public Model
{
private:
	std::vector<Sheep*> mSheeps;
	cocos2d::Scene* mScenes;
	int mShootingCount;
public:
	Space(cocos2d::Scene* scene);
	~Space();

	void Init();
	void Update();

private:
	void Shoot();
};