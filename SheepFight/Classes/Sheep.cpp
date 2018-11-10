#include <Sheep.h>
#include <Defines.h>

USING_NS_CC;

Sheep::Sheep(cocos2d::Scene* scene)
{
	mSprite = Sprite::create(IMG_SHEEP);
	scene->addChild(mSprite);
}
Sheep::~Sheep()
{

}

void Sheep::Init()
{
	setPosition(mLane3);
	
}
void Sheep::Update()
{
	if (isAlive())
	{
		setPosition(getPosition() + Vec2(5, 0));
		if (getPosition().x > mSprite->getContentSize().width + SCREEN_W)
		{
			setAlive(false);
		}
	}
}