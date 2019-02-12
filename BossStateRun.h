#pragma once
#include "BossState.h"

class BossStateRun : public BossState
{
public:
	BossStateRun();
	~BossStateRun();

	BossState* handleState(BOSS * boss, BOSS::BOSS_STATE state) override;
	void enter(BOSS * boss)		override;
	void update(BOSS * boss)	override;
};

