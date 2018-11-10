#pragma once
#include <Model.h>

class Sheep : public Model
{
private:

public:
	Sheep(cocos2d::Scene* scene);
	~Sheep();

	void Init();
	void Update();
};