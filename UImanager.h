#pragma once
#include "skillUI.h"
#include "statusUI.h"
#include "statusSelect.h"
#include "gameNode.h"
class UIMANAGER
{
	SKILLUI* _pSkillUI;
	STATUSUI* _pStatusUI;
	
public:
	UIMANAGER();
	~UIMANAGER();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

