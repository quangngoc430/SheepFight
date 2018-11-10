#include <Rock.h>
#include <Defines.h>

USING_NS_CC;

Rock::Rock(cocos2d::Scene* scene)
{
	mSprite = Sprite::create(IMG_ROCK);
	scene->addChild(mSprite);
}
Rock::~Rock()
{

}

void Rock::Init()
{
	Size size = mSprite->getContentSize();
	int x = random(size.width, SCREEN_W - size.width);
	int y = random(SCREEN_H + size.height, SCREEN_H + size.height + 100);
	setPosition(Vec2(x, y));

	mMoveStep = random(ROCK_FALL_STEP_MIN, ROCK_FALL_STEP_MAX);
}
void Rock::Update()
{
	if (isAlive())
	{
		setPosition(getPosition() - Vec2(0, mMoveStep));
		if (getPosition().y < mSprite->getContentSize().height)
		{
			setAlive(false);
		}
	}
}