#include <Bullet.h>
#include <Defines.h>

USING_NS_CC;

Bullet::Bullet(cocos2d::Scene* scene)
{
	mSprite = Sprite::create(IMG_ROCK);
	scene->addChild(mSprite);
}
Bullet::~Bullet()
{

}

void Bullet::Update()
{
	if (isAlive())
	{
		setPosition(getPosition() + Vec2(0, mMoveStep));
		if (getPosition().y > mSprite->getContentSize().height + SCREEN_H)
		{
			setAlive(false);
		}
	}
}