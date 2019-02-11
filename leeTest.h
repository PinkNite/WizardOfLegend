#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "UImanager.h"

class LEETEST:public gameNode
{
private:
	ITEMMANAGER* _pItemManager;
	UIMANAGER* _pUI;
	
public:
	LEETEST();
	~LEETEST();
	HRESULT init();
	void release();
	void update();
	void render();
};

