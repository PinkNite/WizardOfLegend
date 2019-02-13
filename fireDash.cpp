#include "stdafx.h"
#include "fireDash.h"
#include "magicMgr.h"
#include "player.h"
#include "skillEffectMgr.h"

FIREDASH::FIREDASH():
	_fOffsetTime(0.0f),
	_fTimer(0.0f)
{
}

FIREDASH::~FIREDASH()
{
}

void FIREDASH::init()
{
	SKILL::_nSkillType = static_cast<int>(SKILL::SKILL_TYPE::NONE);
	_fOffsetTime = 0.04f;
	_fTimer = 0.0f;
}

void FIREDASH::update()
{
	_fTimer += TIMEMANAGER->getElapsedTime();


	if (_fTimer >= _fOffsetTime)
	{
		//�һ���
		SKILL::_pMagicMgr->useMagic("dashFlame", SKILL::_pPlayer->getPosX(), _pPlayer->getPosY() + 32.0f, 0.0f, 0.0f, true);
		SKILL::_pSkillEffectMgr->activityEffect("flameBurn", SKILL::_pPlayer->getPosX(), _pPlayer->getPosY() + 48.0f);

		_fTimer = 0.0f;
	}
}

void FIREDASH::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void FIREDASH::render(HDC hdc)
{

}
