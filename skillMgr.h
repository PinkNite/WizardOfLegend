#pragma once
#include "stdafx.h"
#include "skill.h"

class SKILLMGR {
public:
	enum class SKILL_NAME
	{
		NONE = 0,
		FIRE_DASH,
		FIRE_STRIKE,
		SHOKE_NOVA,
		CHAIN_LIGHTNING,
		MAX
	};

	enum class SKILL_KEY
	{
		LBUTTON = 0,
		RBUTTON,
		BTN_Q,
		BTN_E,
		BTN_R,
		BTN_SPACE,
		MAX
	};

private:

	SKILL * _arSkill[static_cast<const int>(PLAYER::SKILL_NAME::MAX)];
	float		_arSkillDelayTime[static_cast<const int>(PLAYER::SKILL_NAME::MAX)];			//스킬 딜레이 시간//스킬 세팅된것이 6개 있다고 치자...
	float		_arCurrentDelayTime[static_cast<const int>(PLAYER::SKILL_NAME::MAX)];		//스킬 쿨 차면 쓸수 있다
	SKILL_NAME	_arSettingSkill[static_cast<const int>(PLAYER::SKILL_KEY::MAX)];			//무슨키에 무슨 스킬이 세팅되어있는지
	int			_nNormalSkillCoount;
	SKILL*		_pCurrentSkill;

public:
	void	init();
	void	update();
	void	release();


	SKILL*	getSkill() { return _pCurrentSkill; }
	void	setSkill(PLAYER::SKILL_NAME eSkillName);


	//
	float	getDeleyTime(PLAYER::SKILL_NAME eSkillName) { return _arSkillDelayTime[static_cast<int>(eSkillName)]; }
	float	getCurrentDeleyTime(PLAYER::SKILL_NAME eSkillName) { return _arCurrentDelayTime[static_cast<int>(eSkillName)]; }
	void	setZeroDeleyTime(PLAYER::SKILL_NAME eSkillName) { _arCurrentDelayTime[static_cast<int>(eSkillName)] = 0.0f; }

	void	setZeroNormalCount() { _nNormalSkillCoount = 0; }
	int		getNormalSkillCount() { return _nNormalSkillCoount; }
	void	addNormalSkillCount(int nOffset) { _nNormalSkillCoount += nOffset; }

	SKILL_NAME	getCurrentSkill(PLAYER::SKILL_KEY skillKey) { return _arSettingSkill[static_cast<int>(skillKey)]; }


	bool	getIsUsingSkill(PLAYER::SKILL_KEY eSkillKey) {
		return _arCurrentDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(eSkillKey)])] >= _arSkillDelayTime[static_cast<int>(_arSettingSkill[static_cast<int>(eSkillKey)])];
	}


};