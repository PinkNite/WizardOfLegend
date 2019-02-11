#pragma once
#include "stdafx.h"
#include "BossState.h"

class BossStateIdle : public BossState
{
public:
	BossStateIdle();
	~BossStateIdle();

	virtual BossState* handleState(BOSS * boss, BOSS::BOSS_STATE state)	override;
	virtual void enter(BOSS * boss)				override;
	virtual void update(BOSS * boss)			override;

};

