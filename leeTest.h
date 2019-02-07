#pragma once
#include "gameNode.h"
#include "itemManager.h"
class LEETEST:public gameNode
{
private:
	ITEMMANAGER* _pItemManager;
public:
	LEETEST();
	~LEETEST();
	HRESULT init();
	void release();
	void update();
	void render();
};

