#pragma once
#include "gameNode.h"
#include "mapEdit.h"
#include "stageScene.h"
#include "minTest.h"
#include "leeTest.h"
#include "introScene.h"

class playGround : public gameNode
{
private:
	gameNode *	_pMapEditScene;
	gameNode*	_pstageScene;
	gameNode*	_pMinTest;
	gameNode*   _pLeeTest;
	gameNode*   _pIntroScene;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();

};

