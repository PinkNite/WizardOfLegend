#include "stdafx.h"
#include "BossStateRun.h"


BossStateRun::BossStateRun()
{
}


BossStateRun::~BossStateRun()
{
}

BossState * BossStateRun::handleState(BOSS * boss, BOSS::BOSS_STATE state)
{
	//boss->setState(BOSS::BOSS_STATE::RUN);
	return nullptr;
}

void BossStateRun::enter(BOSS * boss)
{
	boss->setAction(BOSS::ACTION::RUN, boss->getDiretion());
}

void BossStateRun::update(BOSS * boss)
{
	//boss->moveBoss();
}
