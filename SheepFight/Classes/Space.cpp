#include <Space.h>
#include <Defines.h>

USING_NS_CC;

Space::Space(cocos2d::Scene* scene)
{
	mScenes = scene;
	mSprite = Sprite::create(IMG_SPACE);
	scene->addChild(mSprite);
}
Space::~Space()
{

}

void Space::Init()
{
	mShootingCount = 0;
	setPosition(mLane3 + Vec2(100, 0));

	for (int i = 0; i < MAX_SHEEP; i++)
	{
		Sheep *s = new Sheep(mScenes);
		s->setAlive(false);
		mSheeps.push_back(s);

	}
}
void Space::Update()
{
	mShootingCount++;
	if (mShootingCount == SPACE_SHIP_SHOOT_STEP)
	{
		Shoot();
		mShootingCount = 0;
	}

	for (int i = 0; i < mSheeps.size(); i++)
	{
		Sheep* s = mSheeps.at(i);
		s->Update();
	}
}
void Space::Shoot()
{
	for (int i = 0; i < mSheeps.size(); i++)
	{
		Sheep* s = mSheeps.at(i);
		if (!s->isAlive())
		{
			s->setAlive(true);
			s->setPosition(getPosition() + Vec2(5, 0));
			break;
		}
	}
}