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
class PLAYER;
class UI
{
private:
	SKILLUI* _pSkillUI;//¹Ø¿¡ ½ºÅ³
	GOLDHD* _pGoldHD[2];//°ñµå
	NUMBERS* _pNumbers[2];
	HPBAR* _pHpBar[2];
	STATUSUI* _pStatusUI;//½ºÅÈ
	PLAYERFACE* _pPlayerFace[3];
	MPBAR* _pMpBar;
	PLAYER* _pPlayer;
	bool _isClick;

	//Å×½ºÆ®¿ë
	int _damage;
	float _HP;
	float _MP;

public:
	UI();
	~UI();
	void setLinkPlayer(PLAYER* p) { _pPlayer = p; }
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
public :
	bool getIsClick() { return _isClick; }
	
};

