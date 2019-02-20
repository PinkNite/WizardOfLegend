#include "stdafx.h"
#include "skill.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"

SKILL::SKILL()
{
}

SKILL::~SKILL()
{
}

void SKILL::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
}

void SKILL::pushMagicKey(float fPosX, float fPosY)
{
}

void SKILL::pullMagicKey(float fPosX, float fPosY)
{
}


void SKILL::setMagicMgr(MAGICMGR * pMagicMgr)
{
	_pMagicMgr = pMagicMgr;
}

void SKILL::setSkillEffectMgr(SKILL_EFFECT_MGR * pSkillEffectMgr)
{
	_pSkillEffectMgr = pSkillEffectMgr;
}

void SKILL::setPlayer(PLAYER * pPlayer)
{
	_pPlayer = pPlayer;
}

void SKILL::setMap(MAP * pMap)
{
	_pMap = pMap;
}

