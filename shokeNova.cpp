#include "stdafx.h"
#include "shokeNova.h"
#include "magicMgr.h"
#include "player.h"
#include "skillEffectMgr.h"

SHOKENOVA::SHOKENOVA()
{
}

SHOKENOVA::~SHOKENOVA()
{
}

void SHOKENOVA::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;

	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::SPECIAL);
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::ULTIMATE);
	_bIsKeyDown = false;
	_fTimer = 0.0f;
	_nCount = 0;
}

void SHOKENOVA::update()
{
	_fTimer += TIMEMANAGER->getElapsedTime();
	if (_bIsKeyDown && _fTimer >= 0.2f)
	{
		_pSkillEffectMgr->activityEffect("lightEffect01", SKILL::_pPlayer->getPosX() + RND->getFromFloatTo(-100, 100), SKILL::_pPlayer->getPosY() + RND->getFromFloatTo(-100, 100));
		_pSkillEffectMgr->activityEffect("lightEffect02", SKILL::_pPlayer->getPosX() + RND->getFromFloatTo(-100, 100), SKILL::_pPlayer->getPosY() + RND->getFromFloatTo(-100, 100));
		_pSkillEffectMgr->activityEffect("lightEffect03", SKILL::_pPlayer->getPosX() + RND->getFromFloatTo(-100, 100), SKILL::_pPlayer->getPosY() + RND->getFromFloatTo(-100, 100));
		_pSkillEffectMgr->activityEffect("lightEffect04", SKILL::_pPlayer->getPosX() + RND->getFromFloatTo(-100, 100), SKILL::_pPlayer->getPosY() + RND->getFromFloatTo(-100, 100));
		_fTimer = 0.0f;
	}

	if(!_bIsKeyDown)
	{
		if (_fTimer >= 0.5f)
		{
			SKILL::_pMagicMgr->pushMagicKey("thunder", _fPosX, _fPosY - 248.0f, 0.0f, 0.0f, true);
			_fTimer = 0.0f;
			_nCount++;
		}

		if (_nCount >= 1)
		{
			_pPlayer->setSkill(PLAYER::SKILL_NAME::NONE);
		}
	}
}

void SHOKENOVA::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void SHOKENOVA::render(HDC hdc)
{
}

void SHOKENOVA::pushMagicKey(float fPosX, float fPosY)
{
	//준비마법상태
	//애니메이션 멈추기
	if (!_bIsKeyDown)
	{
		_fTimer = 0.0f;
	}
	_bIsKeyDown = true;
	_nCount = 0;

	_fPosX = SKILL::_pPlayer->getPosX();
	_fPosY = SKILL::_pPlayer->getPosY();
}

void SHOKENOVA::pullMagicKey(float fPosX, float fPosY)
{
	//마법사용
	_fTimer = 0.0f;

	SKILL::_pMagicMgr->pushMagicKey("shokeNova", _fPosX, _fPosY + 32.0f, 0.0f, 0.0f, true);
	SKILL::_pMagicMgr->pushMagicKey("thunder", _fPosX, _fPosY - 248.0f, 0.0f, 0.0f, true);
	_bIsKeyDown = false;

}


