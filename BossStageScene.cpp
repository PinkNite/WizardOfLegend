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
	_boss= new BOSS();
	_boss->init();

	return S_OK;
}

void BossStageScene::update()
{
	_boss->update();
}

void BossStageScene::release()
{
	_boss->release();
}

void BossStageScene::render()
{
	_boss->render(getMemDC());
}
