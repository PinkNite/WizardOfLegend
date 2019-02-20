#include "stdafx.h"
#include "BossStageScene.h"


BossStageScene::BossStageScene()
{
}


BossStageScene::~BossStageScene()
{
}

HRESULT BossStageScene::init()
{
	_isShow = false;

	_pCamera = new CAMERA();
	_pCamera->init(float(_ptMouse.x), float(_ptMouse.y), WINSIZEX, WINSIZEY, 2048, 2048);
	_pCamera->settingCameraRange(0, 0, 2048, 2048);

	_pMagicMgr = new MAGICMGR();
	_pMagicMgr->setLink(_pCamera);

	// boss area
	_pBoss = new BOSS();
	_pBoss->init();
	_pBoss->showBoss();
	_pBoss->setCameraLink(_pCamera);
	_pBoss->setMagicMgr(_pMagicMgr);

	// enemy area
	_pEnemy = new Enemy();
	_pEnemy->init();

	// bubble
	IMAGEMANAGER->addFrameImage("WaterBounce1", "resource/boss/ice/WaterBounce1.bmp", 600, 120, 5, 1, true, Mins::getMazenta());

	_pMagicMgr->addObject("WaterBalls", 100, 40, 40, IMAGEMANAGER->findImage("WaterBounce1"), 4, 120, 120, 10.0f, 1.3f);
	_pMagicMgr->addObject("IceChakram", 100, 40, 40, IMAGEMANAGER->findImage("IceChakram"), 4, 50, 50, 10.0f, 1.3f);

	return S_OK;
}

void BossStageScene::update()
{
	_pCamera->update();
	_pMagicMgr->update();

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::CHAKRAM);
		_pEnemy->skillFire(float(_ptMouse.x), float(_ptMouse.y));
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::BUBBLE);
		_pEnemy->skillFire(float(_ptMouse.x), float(_ptMouse.y));
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_pBoss->dash(float(_ptMouse.x), float(_ptMouse.y));
	}

	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_pEnemy->setEnemy(Enemy::EnemyType::GHOUL, 300.0f, 400.0f);
		_pEnemy->showEnemy();
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_pEnemy->setEnemy(Enemy::EnemyType::GOLEM, 300.0f, 400.0f);
		_pEnemy->showEnemy();
	}
	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		_pEnemy->setEnemy(Enemy::EnemyType::SUMMONER, 300.0f, 400.0f);
		_pEnemy->showEnemy();
	}

	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		_pBoss->setDamage(50.0f);
		_pEnemy->setDamage(50.0f);
	}

	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		_pBoss->setDeath();
		_pEnemy->setDeath();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		_isShow = true;
		_pBoss->showBoss();
		_pEnemy->setEnemy(Enemy::EnemyType::GHOUL, 300.0f, 400.0f);
		_pEnemy->showEnemy();
	}

	if (_isShow)
	{
		_pBoss->update();
		_pEnemy->update();
	}

	KEYANIMANAGER->update();

	_pCamera->setting(float(_ptMouse.x), float(_ptMouse.y));
}

void BossStageScene::release()
{
	_pMagicMgr->release();
	_pBoss->release();
	_pEnemy->release();
}

void BossStageScene::render()
{
	_pCamera->renderinit();
	_pCamera->render(getMemDC());
	if (_isShow)
	{
		_pEnemy->render(getMemDC());
		//_pBoss->render(getMemDC());
	}
}
