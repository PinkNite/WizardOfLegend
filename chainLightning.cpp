#include "stdafx.h"
#include "chainLightning.h"
#include "player.h"
#include "magicMgr.h"
#include "skillEffectMgr.h"
CHAINLIGHTNING::CHAINLIGHTNING()
{
}

CHAINLIGHTNING::~CHAINLIGHTNING()
{
}

void CHAINLIGHTNING::init(PLAYER::SKILL_NAME eSkillName)
{
	SKILL::_eSkillName = eSkillName;
	SKILL::_nSkillType = 0;
	SKILL::_nSkillType += static_cast<int>(SKILL::SKILL_TYPE::SPECIAL);

	_fTimer = 3.0f;
	_fStartPosX = 0.0f;
	_fStartPosY = 0.0f;
	_fAngle = 0.0f;
	_fSpeed = 60.0f;
	_fOffsetTimer = 0.0f;
}

void CHAINLIGHTNING::update()
{
	if (_fTimer < 2.0f)
	{
		_fOffsetTimer += TIMEMANAGER->getElapsedTime();
		_fTimer += TIMEMANAGER->getElapsedTime();

		if (_fOffsetTimer >= 0.2f)
		{
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
					_fTimer = 2.1f;
					return;
				}
			}




			SKILL::_pMagicMgr->pushMagicKey("thunder", _fStartPosX, _fStartPosY - 216.0f, 0.0f, 0.0f, true);
			SKILL::_pSkillEffectMgr->activityEffect("thunderGround", _fStartPosX, _fStartPosY + 34.0f);
			SKILL::_pSkillEffectMgr->activityEffect("electricBurnMark", _fStartPosX, _fStartPosY + 34.0f);


			_fStartPosX += Mins::presentPowerX(_fAngle, _fSpeed);
			_fStartPosY += Mins::presentPowerY(_fAngle, _fSpeed);
			_fOffsetTimer = 0.0f;
		}
	}

}

void CHAINLIGHTNING::release()
{
	SKILL::_pMagicMgr = nullptr;
	SKILL::_pSkillEffectMgr = nullptr;
	SKILL::_pPlayer = nullptr;
}

void CHAINLIGHTNING::render(HDC hdc)
{
}

void CHAINLIGHTNING::pushMagicKey(float fPosX, float fPosY)
{
	_fStartPosX = fPosX;
	_fStartPosY = fPosY;
	_fTimer = 0.0f;
	_fOffsetTimer = 0.0f;
	_fAngle = SKILL::_pPlayer->getAttackAngle();
}

void CHAINLIGHTNING::pullMagicKey(float fPosX, float fPosY)
{

}
