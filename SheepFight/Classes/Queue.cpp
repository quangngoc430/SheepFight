#include "Queue.h"

Queue::Queue() 
{

}

Queue::~Queue()
{

}

bool Queue::empty()
{
	return this->objects.empty();
}

Model* Queue::peek()
{
	return this->objects.at(0);
}

Model* Queue::pop()
{
	Model* model = this->objects.at(0);
	this->objects.erase(this->objects.begin() + 0);
	return model;
}

Model* Queue::push(Model* model)
{
	this->objects.push_back(model);
	return this->objects.at(this->objects.size() - 1);
}

Model* Queue::get(int index)
{
	return this->objects.at(index);
}

Model* Queue::remove(int index)
{
	Model * result = this->objects.at(index);
	this->objects.erase(this->objects.begin() + index);
	return result;
}

int Queue::getSize()
{
	return this->objects.size();
}

bool Queue::isExist(int index)
{
	return (0 <= index && index < this->objects.size());
}