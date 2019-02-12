#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "UI.h"

class LEETEST :public gameNode
{
private:
	ITEMMANAGER* _pItemManager;
	UI* _pUI;
	image* _pMouse;
public:
	LEETEST();
	~LEETEST();
	HRESULT init();
	void release();
	void update();
	void render();
};

