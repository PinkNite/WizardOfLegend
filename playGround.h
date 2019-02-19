#pragma once
#include "gameNode.h"
#include "mapEdit.h"
#include "stageScene.h"
#include "minTest.h"
#include "BossStageScene.h"
#include "leeTest.h"
#include "introScene.h"
#include "gameScene.h"

class playGround : public gameNode
{
private:
	gameNode*	_pMapEditScene;
	gameNode*	_pstageScene;
	gameNode*	_pMinTest;
	gameNode*	_pBossStageScene;
	gameNode*   _pLeeTest;
	gameNode*   _pIntroScene;
	gameNode*	_pGameScene;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();

};

