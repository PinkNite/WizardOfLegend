#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "UI.h"

#include "stdafx.h"
#include "gameNode.h"
#include "player.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"
#include "camera.h"
#include "relics_Type.h"

class LEETEST :public gameNode
{
private:

	ITEMMANAGER* _pItemManager;
	UI* _pUI;
	image* _pMouse;

	PLAYER * _pPlayer;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	CAMERA*				_pCamera;

	//RECT rc;
	//float height;
	//float hp;
	//image* _iImage;
	RELICS_TYPE* _pr;
public:
	LEETEST();
	~LEETEST();
	HRESULT init();
	void release();
	void update();
	void render();

};

