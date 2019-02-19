#include "stdafx.h"
#include "BossStateSkill01.h"


BossStateSkill01::BossStateSkill01()
{
}


BossStateSkill01::~BossStateSkill01()
{
}

BossState * BossStateSkill01::handleState(BOSS * boss, BOSS::BOSS_STATE state)
{
	if (BOSS::BOSS_STATE::SKILL_01 == state)
	{
		//return new BossStateSkill01();
	}

	return nullptr;
}

void BossStateSkill01::enter(BOSS * boss)
{
	boss->setAction(BOSS::ACTION::SKILL_01, boss->getDiretion());
	_timeInterval = 0.0f;
}

void BossStateSkill01::update(BOSS * boss)
{
	_timeInterval += TIMEMANAGER->getElapsedTime();

	// 애니메이션 두바퀴 돌고 나서 발사함
	if (_timeInterval > 0.0f)
	{
		boss->skillFire(static_cast<float>(_ptMouse.x), static_cast<float>(_ptMouse.y));
	}
}
