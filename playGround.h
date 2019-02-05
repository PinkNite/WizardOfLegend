#pragma once
#include "gameNode.h"

#include "mapEdit.h"
#include "stageScene.h"

class playGround : public gameNode
{
private:
	gameNode *	MapEditScene;
	gameNode*	stageScene;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();

};

