#include "stdafx.h"
#include "fireStrike.h"
#include "magicMgr.h"
#include "player.h"
#include "skillEffectMgr.h"

FIRESTRIKE::FIRESTRIKE()
{
}

FIRESTRIKE::~FIRESTRIKE()
{
}

void FIRESTRIKE::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::NORMAL);
	_nCount = 1;
	_bIsOk = true;
}

void FIRESTRIKE::update()
{
	
}

void FIRESTRIKE::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void FIRESTRIKE::render(HDC hdc)
{
}

void FIRESTRIKE::pushMagicKey(float fPosX, float fPosY)
{
	if (_bIsOk  && _pPlayer->getNormalSkillCount() < 3)
	{
		SKILL::_pMagicMgr->pushMagicKey("fireStrike", fPosX, fPosY, 0.0f, 0.0f, true);
		_pPlayer->addNormalSkillCount(1);
		_bIsOk = false;
	}
}

void FIRESTRIKE::pullMagicKey(float fPosX, float fPosY)
{
	_bIsOk = true;
}
