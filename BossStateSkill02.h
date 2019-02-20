#pragma once
#include "BossState.h"

class BossStateSkill02 : public BossState
{
public:
	BossStateSkill02();
	~BossStateSkill02();

	BossState* handleState(BOSS * boss, BOSS::BOSS_STATE state) override;
	void enter(BOSS * boss) override;
	void update(BOSS * boss) override;

};

