#pragma once
#include "skillUI.h"
#include "statusUI.h"
#include "statusSelect.h"
#include "gameNode.h"
#include "goldHD.h"
#include "numbers.h"
class UI
{
	SKILLUI* _pSkillUI;
	STATUSUI* _pStatusUI;
	GOLDHD* _pGoldHD[2];
	NUMBERS* _pNumbers[2];

	bool _isClick;
	
public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

