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

void FIREDASH::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::DASH);
	_fOffsetTime = 0.04f;
	_fTimer = 0.0f;
	_bIsOk = false;
}

void FIREDASH::update()
{
	if (_pPlayer->getDashTime() < 0.5f)
	{
		if (_pPlayer->getCurrentDeleyTime(SKILL::_eSkillName) >= _pPlayer->getDeleyTime(SKILL::_eSkillName))
		{
			if (!_bIsOk && _pPlayer->getDashTime() == 0)
			{
				_bIsOk = true;
			}

			if (!_bIsOk)
			{
				return;
			}

			_fTimer += TIMEMANAGER->getElapsedTime();


			if (_fTimer >= _fOffsetTime)
			{
				//ºÒ»ý¼º
				SKILL::_pMagicMgr->pushMagicKey("dashFlame", SKILL::_pPlayer->getPosX(), _pPlayer->getPosY() + 32.0f, 0.0f, 0.0f, true);
				SKILL::_pSkillEffectMgr->activityEffect("flameBurn", SKILL::_pPlayer->getPosX(), _pPlayer->getPosY() + 64.0f);

				_fTimer = 0.0f;
			}
		}
	}
	else
	{
		if (_pPlayer->getCurrentDeleyTime(SKILL::_eSkillName) >= _pPlayer->getDeleyTime(SKILL::_eSkillName) && _bIsOk) {
			_pPlayer->setZeroDeleyTime(SKILL::_eSkillName);
			_bIsOk = false;
		}
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
