#include "stdafx.h"
#include "reboundingIcicles.h"
#include "player.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"
REBOUNDINGICICLES::REBOUNDINGICICLES()
{
}

REBOUNDINGICICLES::~REBOUNDINGICICLES()
{
}

void REBOUNDINGICICLES::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::SPECIAL);

	_fTimer = 3.0f;
	_fStartPosX = 0.0f;
	_fStartPosY = 0.0f;
	_fAngle = 0.0f;
	_fSpeed = 1000.0f;
	_fOffsetTimer = 0.0f;
	_bIsReturn = false;
	_fTurnTimer = 0.0f;
}

void REBOUNDINGICICLES::update()
{
	if (_fTimer < 1.0f)
	{
		_fTurnTimer += TIMEMANAGER->getElapsedTime();
		_fOffsetTimer += TIMEMANAGER->getElapsedTime();
		_fTimer += TIMEMANAGER->getElapsedTime();

		if (_fOffsetTimer >= 0.05f)
		{

			SKILL::_pMagicMgr->pushMagicKey("iceCrystal", _fStartPosX, _fStartPosY - 64.0f, 0.0f, 0.0f, true);
			//SKILL::_pSkillEffectMgr->activityEffect("thunderGround", _fStartPosX, _fStartPosY + 34.0f);
			//SKILL::_pSkillEffectMgr->activityEffect("electricBurnMark", _fStartPosX, _fStartPosY + 34.0f);


			_fStartPosX += Mins::presentPowerX(_fAngle, _fSpeed * TIMEMANAGER->getElapsedTime());
			_fStartPosY += Mins::presentPowerY(_fAngle, _fSpeed* TIMEMANAGER->getElapsedTime());
			_fOffsetTimer = 0.0f;
		}

		RECT rcTmp;
		RECT rcTile;
		int nTileIndexX = 0;
		int nTileIndexY = 0;
		nTileIndexX = static_cast<int>(_fStartPosX) / SKILL::_pMap->getTileSize();
		nTileIndexY = static_cast<int>(_fStartPosY) / SKILL::_pMap->getTileSize();
		rcTile = RectMakeCenter(_fStartPosX, _fStartPosY, 32, 32);

		if (IntersectRect(&rcTmp, &rcTile, &_pMap->getTile(nTileIndexX, nTileIndexY)->getRectTile()))
		{
			if (_pMap->getTile(nTileIndexX, nTileIndexY)->getTerrian() != TILE::TERRIAN::PASS)
			{
				//_pMap->getTile(nTileIndexX, nTileIndexY)->Tilesefewa();
				_fTimer = 1.0f;
				return;
			}
		}

	}

	if (_fTimer >= 1.0f &&
		_fTimer < 2.0f)
	{
		_fOffsetTimer += TIMEMANAGER->getElapsedTime();
		_fTimer += TIMEMANAGER->getElapsedTime();

		if (!_bIsReturn)
		{
			_bIsReturn = true;
			_fAngle += PI;
		}

		if (_fOffsetTimer >= 0.05f)
		{

			SKILL::_pMagicMgr->pushMagicKey("iceCrystal", _fStartPosX, _fStartPosY - 64.0f, 0.0f, 0.0f, true);
			//SKILL::_pSkillEffectMgr->activityEffect("thunderGround", _fStartPosX, _fStartPosY + 34.0f);
			//SKILL::_pSkillEffectMgr->activityEffect("electricBurnMark", _fStartPosX, _fStartPosY + 34.0f);


			_fStartPosX += Mins::presentPowerX(_fAngle, _fSpeed* TIMEMANAGER->getElapsedTime());
			_fStartPosY += Mins::presentPowerY(_fAngle, _fSpeed* TIMEMANAGER->getElapsedTime());
			_fOffsetTimer = 0.0f;
		}

		_fTurnTimer -= TIMEMANAGER->getElapsedTime();
		if (_fTurnTimer <= 0.0f)
		{
			_fTimer = 2.0f;
		}
	}


}

void REBOUNDINGICICLES::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void REBOUNDINGICICLES::render(HDC hdc)
{
}

void REBOUNDINGICICLES::pushMagicKey(float fPosX, float fPosY)
{
	_fStartPosX = fPosX;
	_fStartPosY = fPosY;
	_fTimer = 0.0f;
	_fOffsetTimer = 0.0f;
	_fAngle = SKILL::_pPlayer->getAttackAngle();
	_bIsReturn = false;
	_fTurnTimer = 0.0f;
}

void REBOUNDINGICICLES::pullMagicKey(float fPosX, float fPosY)
{
}
