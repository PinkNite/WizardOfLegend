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
	_frameCount = 0;
	_isShow = false;

	_boss= new BOSS();
	_boss->init();

	return S_OK;
}

void BossStageScene::update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		_boss->spell01();
	}

	_frameCount++;
	if (_frameCount % 100 == 0 && _isShow == false)
	{
		_isShow = true;
		_boss->showBoss();
	}

	if (_isShow)
	{
		_boss->update();
	}
}

void BossStageScene::release()
{
	_boss->release();
}

void BossStageScene::render()
{
	if (_isShow)
	{
		_boss->render(getMemDC());
	}
}
