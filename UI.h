#pragma once
#include "skillUI.h"
#include "statusUI.h"
#include "statusSelect.h"
#include "gameNode.h"
#include "goldHD.h"
#include "numbers.h"
#include "hpBar.h"
#include "playerFace.h"
class UI
{
	SKILLUI* _pSkillUI;//�ؿ� ��ų
	GOLDHD* _pGoldHD[2];//���
	NUMBERS* _pNumbers[2];
	HPBAR* _pHpBar[2];
	STATUSUI* _pStatusUI;//����
	PLAYERFACE* _pPlayerFace[3];
	bool _isClick;

	//�׽�Ʈ��
	int _damage;
	int _HP;

public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

