#pragma once

#include <vector>
#include <cocos2d.h>
#include "Model.h"

class Queue
{
private:
	std::vector<Model *> objects;
	
public:
	Queue();
	~Queue();

	bool empty();
	Model* peek();
	Model* pop();
	Model* push(Model* model);
	Model* get(int index);
	bool isExist(int index);
	int getSize();
};
