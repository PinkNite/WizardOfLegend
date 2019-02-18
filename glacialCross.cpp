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
}

void GLACIALCROSS::update()
{

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
	while (fAngle < PI / 2.0f + PI/18.0f)
	{
		nFrameY++;
		fAngle -= PI / 2.0f;
	}
	while (fAngle <  PI / 18.0f)
	{
		nFrameX++;
		fAngle -= PI / 18.0f;
	}


	SKILL::_pMagicMgr->pushMagicKey("icePunch", _pPlayer->getAttactPosX(), _pPlayer->getAttactPosY()- 50.0f, _pPlayer->getAttackAngle(), 1000.0f, true, nFrameX,nFrameY);
}

void GLACIALCROSS::pullMagicKey(float fPosX, float fPosY)
{
}
