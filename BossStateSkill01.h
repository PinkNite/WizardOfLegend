#pragma once
#include "BossState.h"

class BossStateSkill01 : public BossState
{
private:
	float _timeInterval;

public:
	BossStateSkill01();
	~BossStateSkill01();

	BossState* handleState(BOSS * boss, BOSS::BOSS_STATE state) override;
	void enter(BOSS * boss) override;
	void update(BOSS * boss) override;
};

