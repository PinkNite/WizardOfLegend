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
	//_pMap->initBossMap("map");
	_pMap->init("map");

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


	// enemy tile locationa
	pair<int, int> tiles[12] = {
		{7, 25}, {4, 26},
	{ 16, 24 }, {25, 22}, {20, 20},
	{20, 20}, {44, 22}, {51, 22},
	{65, 40}, {61, 40}, {60, 36}, {60, 34}
	};

	for (int i = 0; i < 12; i++)
	{
		Enemy* enemy = new Enemy();
		enemy->init();
		enemy->setMap(_pMap);
		enemy->setPlayer(_pPlayer);
		enemy->setCameraLink(_pCamera);

		float x = tiles[i].first * _pMap->getTileSize();
		float y = tiles[i].second * _pMap->getTileSize();
		
		int type = RND->getInt(3);
		switch (type)
		{
		case 0:
			enemy->setEnemy(Enemy::EnemyType::GHOUL, x, y);
			break;
		case 1:
			enemy->setEnemy(Enemy::EnemyType::GOLEM, x, y);
			break;
		case 2:
			enemy->setEnemy(Enemy::EnemyType::SUMMONER, x, y);
			break;
		}

		//enemy->showEnemy();

		_vEnemyList.push_back(enemy);
	}

	_pMagicMgr->setEnemyList(_vEnemyList);

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
	if (_fTimeSet > 0.7f)
	{
		// 길찾기 업데이트 
		for (int i = 0; i < _vEnemyList.size(); i++)
		{
			if (_vEnemyList[i]->getActionState() == Enemy::ActionState::HIDDEN) continue;
			if (_vEnemyList[i]->getActionState() == Enemy::ActionState::DEATH) continue;
			if (_vEnemyList[i]->getActionState() == Enemy::ActionState::DEATH_END) continue;

			POINT startTile = _pAStar->getTileIndex(_vEnemyList[i]->getPosX(), _vEnemyList[i]->getPosY());
			POINT endTile = _pAStar->getTileIndex(_pPlayer->getPosX(), _pPlayer->getPosY());
			_pAStar->startFinder(startTile.x, startTile.y, endTile.x, endTile.y);
			_pAStar->pathFinder();
			_pPathList = _pAStar->getPath();
			if (0 < _pPathList.size())
			{
				_vEnemyList[i]->setShortPath(_pPathList);
			}
		}
		_fTimeSet = 0.f;
	}

	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::CHAKRAM);

		_vEnemyList[0]->skillAttack(_pPlayer->getPosX(), _pPlayer->getPosY());
	}

	if (KEYMANAGER->isOnceKeyDown('2'))
	{
		//_pBoss->spell01(BOSS::SKILL_TYPE::BUBBLE);
		_vEnemyList[0]->skillAttack(_pPlayer->getPosX(), _pPlayer->getPosY());
	}

	if (KEYMANAGER->isOnceKeyDown('3'))
	{
		_pBoss->dash(_pPlayer->getPosX(), _pPlayer->getPosY());
	}

	if (KEYMANAGER->isOnceKeyDown('6'))
	{
		_vEnemyList[0]->setEnemy(Enemy::EnemyType::GHOUL, 300.0f, 400.0f);
		_vEnemyList[0]->showEnemy();
	}
	if (KEYMANAGER->isOnceKeyDown('7'))
	{
		_vEnemyList[0]->setEnemy(Enemy::EnemyType::GOLEM, 300.0f, 400.0f);
		_vEnemyList[0]->showEnemy();
	}
	if (KEYMANAGER->isOnceKeyDown('8'))
	{
		_vEnemyList[0]->setEnemy(Enemy::EnemyType::SUMMONER, 300.0f, 400.0f);
		_vEnemyList[0]->showEnemy();
	}

	if (KEYMANAGER->isOnceKeyDown('9'))
	{
		_pBoss->setDamage(50.0f);
		_vEnemyList[0]->setDamage(50.0f);
	}

	if (KEYMANAGER->isOnceKeyDown('0'))
	{
		_pBoss->setDeath();
		_vEnemyList[0]->setDeath();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SHIFT))
	{
		//_pBoss->showBoss();
		_vEnemyList[0]->showEnemy();
	}

	for (int i = 0; i < _vEnemyList.size(); i++)
	{
		_vEnemyList[i]->update();
	}

	_pBoss->update();

	KEYANIMANAGER->update();

	//_pMap->settingLimitRect();
	_pCamera->setting(_pPlayer->getPosX(), _pPlayer->getPosY());
}

void BossStageScene::release()
{
	_pMagicMgr->release();
	_pBoss->release();
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
