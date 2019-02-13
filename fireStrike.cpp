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

void FIRESTRIKE::init()
{
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::NORMAL);
	
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

void FIRESTRIKE::useMagic(float fPosX, float fPosY)
{
	SKILL::_pMagicMgr->useMagic("fireStrike", fPosX, fPosY, 0.0f, 0.0f, true);
}
