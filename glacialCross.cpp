#include "stdafx.h"
#include "glacialCross.h"
#include "player.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"


GLACIALCROSS::GLACIALCROSS()
{
}

GLACIALCROSS::~GLACIALCROSS()
{
}

void GLACIALCROSS::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::SPECIAL);
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::ULTIMATE);

	_fTimer = 4.0f;
	_fStartPosX = 0.0f;
	_fStartPosY = 0.0f;
	for (int i = 0; i < 3; i++)
	{
		_arAngle[i] = 0.0f;
	}
	_fSpeed = 300.0f;
	_fOffsetTimer = 0.0f;
	_bIsPunch = false;
}

void GLACIALCROSS::update()
{
	_fTimer += TIMEMANAGER->getElapsedTime();
	if (_fTimer <= 3.0f)
	{
		_fStartPosX += Mins::presentPowerX(_arAngle[1], _fSpeed * TIMEMANAGER->getElapsedTime());
		_fStartPosY += Mins::presentPowerY(_arAngle[1], _fSpeed * TIMEMANAGER->getElapsedTime());

		if (_fTimer >= 0.3f && _bIsPunch)
		{
			//≈Õ¡¯¥Ÿ
			_arAngle[0] = _arAngle[1] - PI/6.0f;
			_arAngle[2] = _arAngle[1] + PI / 6.0f;

			if (_arAngle[0] < 0.0f)
			{
				_arAngle[0] = PI2 + _arAngle[0];
			}
			if (_arAngle[2] > PI2)
			{
				_arAngle[2] = _arAngle[2] - PI2;
			}

			for (int i = 0; i < 3; i++)
			{
				int nFrameX = 0;
				int nFrameY = 0;
				float fAngle = 0.0f;
				fAngle = _arAngle[i];
				
				while (fAngle > PI / 2.0f + PI / 18.0f)
				{
					nFrameY++;
					fAngle -= PI / 2.0f;
				}

				while (fAngle > PI / 18.0f)
				{
					nFrameX++;
					fAngle -= PI / 18.0f;
				}

				SKILL::_pMagicMgr->pushMagicKey("iceBullet", _fStartPosX, _fStartPosY, _arAngle[i], _fSpeed * 2.0f, true, nFrameX, nFrameY);

			}


			_bIsPunch = false;
		}

	}

}

void GLACIALCROSS::release()
{
}

void GLACIALCROSS::render(HDC hdc)
{
}

void GLACIALCROSS::pushMagicKey(float fPosX, float fPosY)
{
	int nFrameX = 0;
	int nFrameY = 0;
	float fAngle = 0.0f;
	fAngle = _pPlayer->getAttackAngle();
	while (fAngle > PI / 2.0f + PI / 18.0f)
	{
		nFrameY++;
		fAngle -= PI / 2.0f;
	}
	while (fAngle > PI / 18.0f)
	{
		nFrameX++;
		fAngle -= PI / 18.0f;
	}


	_fTimer = 0.0f;
	_fStartPosX = _pPlayer->getAttactPosX();
	_fStartPosY = _pPlayer->getAttactPosY();
	for (int i = 0; i < 3; i++)
	{
		_arAngle[i] = 0.0f;
	}
	_arAngle[1] = _pPlayer->getAttackAngle();

	SKILL::_pMagicMgr->pushMagicKey("icePunch", _pPlayer->getAttactPosX(), _pPlayer->getAttactPosY(), _arAngle[1], _fSpeed, true, nFrameX, nFrameY);

	_bIsPunch = true;
}

void GLACIALCROSS::pullMagicKey(float fPosX, float fPosY)
{
}
