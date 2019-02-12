#pragma once

#include "stdafx.h"
#include "gameNode.h"
#include "player.h"
#include "skillEffectMgr.h"
#include "magicMgr.h"

class MINTESTSCENE : public gameNode
{
private:
	PLAYER * _pPlayer;
	MAGICMGR*			_pMagicMgr;
	SKILL_EFFECT_MGR*	_pSkillEffectMgr;

public:
	MINTESTSCENE();
	~MINTESTSCENE();

	HRESULT init() override;
	void update() override;
	void release() override;
	void render() override;
};