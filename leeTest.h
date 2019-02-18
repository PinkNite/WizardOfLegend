#pragma once
#include "gameNode.h"
#include "itemManager.h"
#include "UI.h"
#include "player.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"

class LEETEST :public gameNode
{
private:

	ITEMMANAGER* _pItemManager;
	UI* _pUI;
	image* _pMouse;
	PLAYER * _pPlayer;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	
public:
	LEETEST();
	~LEETEST();
	HRESULT init();
	void release();
	void update();
	void render();

};

