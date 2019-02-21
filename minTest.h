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


class MINTESTSCENE : public gameNode
{
private:
	PLAYER * _pPlayer;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;
	CAMERA*				_pCamera;

	BOSS* _pBoss;
	bool _isBoss;

	MAP*		_pMap;

	STATUEMGR*	_pStatueMgr;
public:
	MINTESTSCENE();
	~MINTESTSCENE();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};