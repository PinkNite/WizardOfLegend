#pragma once
#include "gameNode.h"
#include "boss.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"
#include "camera.h"
#include "Enemy.h"
#include "player.h"
#include "map.h"
#include "StatueMgr.h"
#include "UI.h"
#include "itemManager.h"

class BossStageScene :	public gameNode
{
private:
	MAP*				_pMap;
	BOSS*				_pBoss;
	PLAYER*				_pPlayer;
	CAMERA*				_pCamera;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;

	UI*			_pUI;
	image*		_pMouse;
	STATUEMGR*	_pStatueMgr;
	ITEMMANAGER* _pItemManager;

	float		_fDeathTimer;

public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};
 
