#include "stdafx.h"
#include "skill.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"
#include "player.h"

SKILL::SKILL()
{
}

SKILL::~SKILL()
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
