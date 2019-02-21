#pragma once
#include "gameNode.h"
#include "boss.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"
#include "camera.h"
#include "Enemy.h"
#include "player.h"
#include "map.h"
#include "aStar.h"

class BossStageScene :	public gameNode
{
private:
	MAP*				_pMap;
	BOSS*				_pBoss;
	Enemy*				_pEnemy;
	PLAYER*				_pPlayer;
	CAMERA*				_pCamera;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	ASTAR*				_pAStar;
public:
	BossStageScene();
	~BossStageScene();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};

