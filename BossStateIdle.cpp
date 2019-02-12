#include "stdafx.h"
#include "BossStateIdle.h"


BossStateIdle::BossStateIdle()
{
}


BossStateIdle::~BossStateIdle()
{
}

BossState* BossStateIdle::handleState(BOSS * boss, BOSS::BOSS_STATE state)
{
	if (BOSS::BOSS_STATE::RUN == state)
	{
		//return new BossStateRun();
	}
	return nullptr;
}

void BossStateIdle::enter(BOSS * boss)
{
	boss->setAction(BOSS::ACTION::IDLE);
}

void BossStateIdle::update(BOSS * boss)
{
}

