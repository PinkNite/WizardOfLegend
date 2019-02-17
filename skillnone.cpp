#include "stdafx.h"
#include "skillnone.h"
#include "player.h"


NONESKILL::NONESKILL()
{
}

NONESKILL::~NONESKILL()
{
}



void NONESKILL::update()
{
}

void NONESKILL::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void NONESKILL::render(HDC hdc)
{
}
