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
	_pCamera = new CAMERA();
	_pCamera->init(float(_ptMouse.x), float(_ptMouse.y), WINSIZEX, WINSIZEY, 2048, 2048);
	_pCamera->settingCameraRange(0, 0, 2048, 2048);

	_pMagicMgr = new MAGICMGR();
	_pMagicMgr->setLink(_pCamera);

	_pMap = new MAP();
	_pMap->initBossMap("map");

	_pMap->setCamera(_pCamera);

	_pAStar = new ASTAR();
	_pAStar->init(8, _pMap);

	_pPlayer = new PLAYER();
	_pPlayer->setLinkMap(_pMap);
	_pPlayer->init(500.0f, 500.0f);


	_pSkillEffectMgr = new SKILL_EFFECT_MGR();


	int nSizeX = _pMap->getMapCountX() * _pMap->getTileSize();
	int nSizeY = _pMap->getMapCountY() * _pMap->getTileSize();
	_pCamera->init(WINSIZEX / 2, WINSIZEY / 2, WINSIZEX, WINSIZEY, nSizeX, nSizeY);
	_pMap->setCamera(_pCamera);

	_pMagicMgr = new MAGICMGR();
	_pMagicMgr->setLink(_pCamera);
	_pMagicMgr->setPlayer(_pPlayer);
	_pMagicMgr->setMap(_pMap);


	_pMagicMgr->addObject("dashFlame", 100, 64, 64,
		IMAGEMANAGER->addFrameImage("dashFlame", "resource/skill/flame.bmp", 1408, 384, 11, 3, true, Mins::getMazenta()),
		6, 128, 128, 2.0f, 10.0f, false);
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->addFrameImage("flameBurn", "resource/skill/flameBurnMark.bmp", 192, 48, 4, 1, true, RGB(255, 0, 255)),
		1, 48, 48, 1000, "flameBurn");

	IMAGEMANAGER->addFrameImage("fireStrike", "resource/skill/fireStrike.bmp", 1280, 128, 10, 1, true, Mins::getMazenta());

	_pMagicMgr->addObject("fireStrike", 100, 128, 128, IMAGEMANAGER->findImage("fireStrike"), 20, 128, 128, 0.5f, 12.0f, false);


	//쇼크노바
	IMAGEMANAGER->addFrameImage("lightEffect01", "resource/skill/lightEffect01.bmp", 256, 64, 4, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("lightEffect02", "resource/skill/lightEffect02.bmp", 256, 64, 4, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("lightEffect03", "resource/skill/lightEffect03.bmp", 256, 64, 4, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("lightEffect04", "resource/skill/lightEffect04.bmp", 256, 64, 4, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("shokeNova", "resource/skill/shokeNova.bmp", 2048, 512, 4, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("thunder", "resource/skill/thunder.bmp", 307, 1024, 4, 2, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("thunderGround", "resource/skill/thunderGround.bmp", 135, 31, 3, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addImage("upRock", "resource/skill/upRock.bmp", 121, 128, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("electricBurnMark", "resource/skill/electricBurnMark.bmp", 192, 48, 4, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("bicRock", "resource/skill/bicRock.bmp", 512, 128, 4, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("smallRock", "resource/skill/smallRock.bmp", 256, 64, 4, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addImage("upRock", "resource/skill/upRock.bmp", 121, 128, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("iceCrystal", "resource/skill/iceCrystal.bmp", 700, 199, 5, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("dlbSmallRock", "resource/skill/dlbSmallRock.bmp", 128, 32, 4, 1, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("icePunch", "resource/skill/icePunch.bmp", 1350, 600, 9, 4, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("iceBullet", "resource/skill/iceBullet.bmp", 540, 240, 9, 4, true, Mins::getMazenta());

	IMAGEMANAGER->addFrameImage("dropRock", "resource/skill/dropRock.bmp", 32, 32, 1, 1, true, Mins::getMazenta());
	IMAGEMANAGER->addFrameImage("dropRightRock", "resource/skill/dropRightRock.bmp", 32, 32, 1, 1, true, Mins::getMazenta());


	KEYANIMANAGER->addObject("shokeNova");
	int arr[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayCoordinateFrameAnimation("shokeNova", "shokeNova", "shokeNova", arr, 4, 16, true, 3);

	KEYANIMANAGER->addObject("Rock");
	KEYANIMANAGER->addArrayCoordinateFrameAnimation("Rock", "bicRock", "bicRock", arr, 4, 16, true, 16);
	KEYANIMANAGER->addArrayCoordinateFrameAnimation("Rock", "smallRock", "smallRock", arr, 4, 16, true, 16);
	KEYANIMANAGER->addArrayCoordinateFrameAnimation("Rock", "dlbSmallRock", "dlbSmallRock", arr, 4, 16, true, 16);


	_pMagicMgr->addObject(KEYANIMANAGER->findAnimation("shokeNova", "shokeNova"), "shokeNova", 3, 512, 512, IMAGEMANAGER->findImage("shokeNova"), 6, 512, 512, 1.0f, 12.0f, false);

	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("lightEffect01"), 6, 64, 64, 100, "lightEffect01");
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("lightEffect02"), 6, 64, 64, 100, "lightEffect02");
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("lightEffect03"), 6, 64, 64, 100, "lightEffect03");
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("lightEffect04"), 6, 64, 64, 100, "lightEffect04");


	_pMagicMgr->addObject("thunder", 100, 76, 512, IMAGEMANAGER->findImage("thunder"), 16, 76, 512, 0.5f, 12.0f, true);
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("thunderGround"), 6, 45, 31, 100, "thunderGround");
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("electricBurnMark"), 4, 48, 48, 100, "electricBurnMark");


	_pMagicMgr->addObject(KEYANIMANAGER->findAnimation("Rock", "bicRock"), "bicRock", 100, 128, 128, IMAGEMANAGER->findImage("bicRock"), 16, 128, 128, 0.5f, 13.0f, true);
	_pMagicMgr->addObject(KEYANIMANAGER->findAnimation("Rock", "smallRock"), "smallRock", 100, 64, 64, IMAGEMANAGER->findImage("smallRock"), 16, 64, 64, 1.0f, 11.0f, true);
	_pMagicMgr->addObject(KEYANIMANAGER->findAnimation("Rock", "dlbSmallRock"), "dlbSmallRock", 100, 32, 32, IMAGEMANAGER->findImage("dlbSmallRock"), 16, 32, 32, 0.3f, 10.0f, true);

	_pMagicMgr->addObject("upRock", 10, 121, 128, IMAGEMANAGER->findImage("upRock"), 1, 121, 128, 0.3f, 20.0f, false);

	_pMagicMgr->addObject("iceCrystal", 100, 140, 199, IMAGEMANAGER->findImage("iceCrystal"), 15, 140, 199, 0.3f, 14.0f, false);

	_pMagicMgr->addObject("icePunch", 10, 110, 110, IMAGEMANAGER->findImage("icePunch"), 0, 0, 0.3f, 20.0f, false);

	_pMagicMgr->addObject("iceBullet", 100, 25, 25, IMAGEMANAGER->findImage("iceBullet"), 0, 0, 0.3f, 14.0f, true);

	_pPlayer->setLink(_pMagicMgr, _pSkillEffectMgr);

	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("dropRock"), 1, 32, 32, 1200, "dropRock");
	_pSkillEffectMgr->addEffect(IMAGEMANAGER->findImage("dropRightRock"), 1, 32, 32, 1200, "dropRightRock");

	_pMagicMgr->addObject("dropRock", 1200, 32, 32, IMAGEMANAGER->findImage("dropRock"), 0, 0, 0.3f, 0.0f, false);
	_pMagicMgr->addObject("dropRightRock", 1200, 32, 32, IMAGEMANAGER->findImage("dropRightRock"), 0, 0, 0.3f, 0.0f, false);


	// enemy area
	_pEnemy = new Enemy();
	_pEnemy->init();
	_pEnemy->setMap(_pMap);
	_pEnemy->setPlayer(_pPlayer);
	_pEnemy->setCameraLink(_pCamera);
	_pEnemy->setEnemy(Enemy::EnemyType::GHOUL, 200.0f, 400.0f);
	_pEnemy->showEnemy();

	_pMagicMgr->setEnemy(_pEnemy);

	_pCamera->setting(static_cast<int>(_pPlayer->getPosX()), static_cast<int>(_pPlayer->getPosY()));
	_pPlayer->setCameraLink(_pCamera);

	// boss area
	_pBoss = new BOSS();
	_pBoss->init();
	_pBoss->setCameraLink(_pCamera);
	_pBoss->setMagicMgr(_pMagicMgr);
	_pBoss->setPlayer(_pPlayer);

	_pMagicMgr->setBoss(_pBoss);

	// bubble
	IMAGEMANAGER->addFrameImage("WaterBounce1", "resource/boss/ice/WaterBounce1.bmp", 600, 120, 5, 1, true, Mins::getMazenta());

	_pMagicMgr->addObject("WaterBalls", 100, 40, 40, IMAGEMANAGER->findImage("WaterBounce1"), 4, 120, 120, 10.0f, 1.3f, 10.0f, false);
	_pMagicMgr->addObject("IceChakram", 100, 40, 40, IMAGEMANAGER->findImage("IceChakram"), 4, 50, 50, 10.0f, 1.3f, 10.0f, false);

	_pMap->settingLimitRect();
	_pMap->drawMap(_pCamera->getBackGoroundBuffer());

	return S_OK;
}

void BossStageScene::update()
{
	_pCamera->update();
	_pMagicMgr->update();
	_pPlayer->update();
	_pSkillEffectMgr->update();

	_fTimeSet += TIMEMANAGER->getElapsedTime();
	if (_fTimeSet > 0.5f)
	{
		// 길찾기 업데이트 
		POINT startTile = _pAStar->getTileIndex(_pEnemy->getPosX(), _pEnemy->getPosY());
		POINT endTile = _pAStar->getTileIndex(_pPlayer->getPosX(), _pPlayer->getPosY());
		_pAStar->startFinder(startTile.x, startTile.y, endTile.x, endTile.y);
		_pAStar->pathFinder();
		_pPathList = _pAStar->getPath();
		if (0 < _pPathList.size())
		{
			_pEnemy->setShortPath(_pPathList);
		}
		_fTimeSet = 0.f;
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::CHAKRAM);
		_pEnemy->skillAttack(_pPlayer->getPosX(), _pPlayer->getPosY());
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::BUBBLE);
		_pEnemy->skillAttack(_pPlayer->getPosX(), _pPlayer->getPosY());
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_pBoss->dash(_pPlayer->getPosX(), _pPlayer->getPosY());
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
		//_pBoss->showBoss();
		_pEnemy->showEnemy();
	}

	_pEnemy->update();
	_pBoss->update();

	KEYANIMANAGER->update();

	//_pMap->settingLimitRect();
	_pCamera->setting(_pPlayer->getPosX(), _pPlayer->getPosY());
}

void BossStageScene::release()
{
	_pMagicMgr->release();
	_pBoss->release();
	_pEnemy->release();
	_pPlayer->release();
	_pMap->release();
}

void BossStageScene::render()
{
	//_pMap->render(_pCamera->getMemDC());
	_pCamera->renderinit();
	_pSkillEffectMgr->render(_pCamera->getMemDC());
	_pCamera->render(getMemDC());
}
