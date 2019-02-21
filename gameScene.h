#pragma once
#include "stdafx.h"
#include "gameNode.h"
#include "player.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"
#include "camera.h"
#include "boss.h"
#include "map.h"
#include "StatueMgr.h"
#include "UI.h"
#include "Enemy.h"

#include "itemManager.h"
#include "UI.h"

class GAMESCENE : public gameNode
{
public:
	GAMESCENE();
	~GAMESCENE();

	virtual HRESULT init()	override;
	virtual void release()	override;
	virtual void update()	override;
	virtual void render()	override;

private:
	PLAYER * _pPlayer;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	CAMERA*				_pCamera;

	BOSS* _pBoss;
	bool _isBoss;

	MAP*		_pMap;

	STATUEMGR*	_pStatueMgr;

	float		_fDeathTimer;
	list<ASTAR::TILENODE*>		_pPathList;

	vector<Enemy*>		_vEnemyList;

	float		_fTimeSet;
	ASTAR*				_pAStar;

	ITEMMANAGER* _pItemManager;
	UI* _pUI;
	image* _pMouse;
};

