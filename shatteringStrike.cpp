#include "stdafx.h"
#include "shatteringStrike.h"
#include "magicMgr.h"
#include "player.h"
#include "skillEffectMgr.h"

SHATTERINGSTRIKE::SHATTERINGSTRIKE()
{
}

SHATTERINGSTRIKE::~SHATTERINGSTRIKE()
{
}

void SHATTERINGSTRIKE::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;

	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::SPECIAL);
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::ULTIMATE);
	_fTimer = 0.0f;
	_bIsUse = false;
}

void SHATTERINGSTRIKE::update()
{
	_fTimer += TIMEMANAGER->getElapsedTime();
	if (_fTimer >= 0.3f && !_bIsUse)
	{
		for (int i = 0; i < 2; i++)
		{
			//_pSkillEffectMgr->activityEffect("dropRock", _fPosX+RND->getFromFloatTo(-32,32), _fPosY + RND->getFromFloatTo(-32, 32));
			//_pSkillEffectMgr->activityEffect("dropRightRock", _fPosX + RND->getFromFloatTo(-32, 32), _fPosY + RND->getFromFloatTo(-32, 32));

			_pMagicMgr->pushMagicKey("dropRock", _pPlayer->getAttactPosX() + RND->getFromFloatTo(-32, 32), _pPlayer->getAttactPosY() + RND->getFromFloatTo(-32, 32), PI2 - PI / 2.0f, 50.0f, true, 0, 0);
			_pMagicMgr->pushMagicKey("dropRightRock", _pPlayer->getAttactPosX() + RND->getFromFloatTo(-32, 32), _pPlayer->getAttactPosY() + RND->getFromFloatTo(-32, 32), PI2 - PI / 2.0f, 50.0f, true,0,0);
		}

		float	fAngle = 0.0f;
		for (int i = 0; i < 36; i++)
		{
			_pMagicMgr->pushMagicKey("dlbSmallRock", _pPlayer->getAttactPosX(), _pPlayer->getAttactPosY(), fAngle,600.0f, true);
			fAngle += PI / 18.0f;
		}
		_bIsUse = true;
	}
	

	_fPosX = Mins::presentPowerX(PI / 2.0f, 100.0f*TIMEMANAGER->getElapsedTime());
	_fPosY = Mins::presentPowerY(PI / 2.0f, 100.0f*TIMEMANAGER->getElapsedTime());
}

void SHATTERINGSTRIKE::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void SHATTERINGSTRIKE::render(HDC hdc)
{
}

void SHATTERINGSTRIKE::pushMagicKey(float fPosX, float fPosY)
{
	_fPosX = _pPlayer->getAttactPosX();
	_fPosY = _pPlayer->getAttactPosY();
	_pMagicMgr->pushMagicKey("upRock", _fPosX, _fPosY, PI / 2.0f, 100.0f, true);
	_fTimer = 0.0f;
	_bIsUse = false;
}

void SHATTERINGSTRIKE::pullMagicKey(float fPosX, float fPosY)
{
}
