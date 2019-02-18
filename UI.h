#pragma once
#include "skillUI.h"
#include "statusUI.h"
#include "statusSelect.h"
#include "gameNode.h"
#include "goldHD.h"
#include "numbers.h"
#include "hpBar.h"
#include "playerFace.h"
#include "mpbar.h"
#include "player.h"
class UI
{
private:
	SKILLUI* _pSkillUI;//�ؿ� ��ų
	GOLDHD* _pGoldHD[2];//���
	NUMBERS* _pNumbers[2];
	HPBAR* _pHpBar[2];
	STATUSUI* _pStatusUI;//����
	PLAYERFACE* _pPlayerFace[3];
	MPBAR* _pMpBar;
	PLAYER* _pPlayer;
	bool _isClick;

	//�׽�Ʈ��
	int _damage;
	float _HP;
	float _MP;

public:
	UI();
	~UI();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
public :
	void setLinkPlayer(PLAYER* p) { _pPlayer = p; }
	bool getIsClick() { return _isClick; }
	
};

