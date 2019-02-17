#include "stdafx.h"
#include "skillMgr.h"
#include "skillnone.h"
#include "fireDash.h"
#include "fireStrike.h"
#include "shokeNova.h"
#include "chainLightning.h"

void SKILLMGR::init()
{
	_arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::NONE)] = new NONESKILL();
	_arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::FIRE_DASH)] = new FIREDASH();
	_arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::FIRE_STRIKE)] = new FIRESTRIKE();
	_arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::SHOKE_NOVA)] = new SHOKENOVA();
	_arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::CHAIN_LIGHTNING)] = new CHAINLIGHTNING();

	for (int i = 0; i < static_cast<int>(SKILLMGR::SKILL_NAME::MAX); i++)
	{
		//_arSkill[i]->init(static_cast<SKILLMGR::SKILL_NAME>(i));
		_arCurrentDelayTime[i] = 0.0f;

	}
	_pCurrentSkill = _arSkill[static_cast<int>(SKILLMGR::SKILL_NAME::NONE)];



	_arSkillDelayTime[static_cast<int>(SKILLMGR::SKILL_NAME::NONE)] = 0.0f;
	_arSkillDelayTime[static_cast<int>(SKILLMGR::SKILL_NAME::FIRE_DASH)] = 5.0f;
	_arSkillDelayTime[static_cast<int>(SKILLMGR::SKILL_NAME::FIRE_STRIKE)] = 0.5f;

	_arSkillDelayTime[static_cast<int>(SKILLMGR::SKILL_NAME::SHOKE_NOVA)] = 5.0f;
	_arSkillDelayTime[static_cast<int>(SKILLMGR::SKILL_NAME::CHAIN_LIGHTNING)] = 5.0f;


	for (int i = 0; i < static_cast<int>(SKILLMGR::SKILL_NAME::MAX); i++)
	{
		_arCurrentDelayTime[i] = _arSkillDelayTime[i];
	}


	for (int i = 0; i < static_cast<int>(SKILLMGR::SKILL_KEY::MAX); i++)
	{
		_arSettingSkill[i] = SKILLMGR::SKILL_NAME::NONE;
	}

	//임시적으로 쓰는것 이제 유아이랑도 엮어서 처리해야함
	_arSettingSkill[static_cast<int>(SKILLMGR::SKILL_KEY::BTN_SPACE)] = SKILLMGR::SKILL_NAME::FIRE_DASH;
	_arSettingSkill[static_cast<int>(SKILLMGR::SKILL_KEY::LBUTTON)] = SKILLMGR::SKILL_NAME::FIRE_STRIKE;
	_arSettingSkill[static_cast<int>(SKILLMGR::SKILL_KEY::BTN_Q)] = SKILLMGR::SKILL_NAME::SHOKE_NOVA;
	_arSettingSkill[static_cast<int>(SKILLMGR::SKILL_KEY::RBUTTON)] = SKILLMGR::SKILL_NAME::CHAIN_LIGHTNING;
}

void SKILLMGR::update()
{
}

void SKILLMGR::release()
{
}

void SKILLMGR::setSkill(PLAYER::SKILL_NAME eSkillName)
{
}
