#include "stdafx.h"
#include "stoneShot.h"
#include "magicMgr.h"
#include "player.h"
#include "skillEffectMgr.h"

STONESHOT::STONESHOT()
{
}

STONESHOT::~STONESHOT()
{
}

void STONESHOT::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::NORMAL);
	_nCount = 1;
	_bIsOk = true;
}

void STONESHOT::update()
{
}

void STONESHOT::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void STONESHOT::render(HDC hdc)
{
}

void STONESHOT::pushMagicKey(float fPosX, float fPosY)
{
	if (_bIsOk  && _pPlayer->getNormalSkillCount() < 3)
	{
		if (_pPlayer->getNormalSkillCount() < 1)
		{
			SKILL::_pMagicMgr->pushMagicKey("bicRock", _pPlayer->getAttactPosX(), _pPlayer->getAttactPosY(), _pPlayer->getAttackAngle(), 400.0f, true);
		}
		else
		{
			SKILL::_pMagicMgr->pushMagicKey("smallRock", _pPlayer->getAttactPosX(), _pPlayer->getAttactPosY(), _pPlayer->getAttackAngle(), 400.0f, true);
		}
		_pPlayer->addNormalSkillCount(1);
		_bIsOk = false;
	}
}

void STONESHOT::pullMagicKey(float fPosX, float fPosY)
{
	_bIsOk = true;

}